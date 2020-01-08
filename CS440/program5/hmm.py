"""
CS 440 Hidden Markov Model Assignment

Travis Mandel, modified from
an assignment by Sravana Reddy
"""

import string
import math

# The HMM Model
#
# In this HMM, states and observations are represented by strings (usually single characters)
#
# Transitions are stored as a nested map from starting state
#  and ending state to probability. So to get the
# probability of going from state i to state j, one
# should do self.transitions[i][j]
#
# The initial probabilities are stored in the same data structure,
# but the starting state is set to a special value '#'
# So self.transitions['#'][j] representes the probability of being
# in state j initially.
#
# Emissions are stored as a nested map from starting state
#  and emission to probability. So to get the
# probability of getting emission e in state i, one
# should do self.emissions[i][e]
#
# NOTE: Emissions/Transitions that are missing from the maps are assumed to
# have probability 0.
#
# You can get the states with self.states, but be careful as this does not
# include the start state #.
class HMM:

    def __init__(self, transitions=None, emissions=None):
        self.transitions = transitions
        self.emissions = emissions
        if self.emissions:
            self.states = list(self.emissions.keys()) #note: self.states excludes the start state
            

    #Gets the probability of an emission that is not in the emissions dicts
    # might be helpful for your filter and viterbi functions
    def getUnkEmis(self, s):
        if "UNKNOWN" in self.emissions[s]:
            return self.emissions[s]["UNKNOWN"]
        else:
            return 0
        
    # Read HMM from files
    # It reads separate files for the emissions (basename.emit) and for the
    # transitions (basename.trans)
    # Files are read line-by-line, with a separate transition or emission
    # probability on each line
    def load(self, basename):
        
        transf = open(basename+ ".trans", "r")
        self.transitions = {}
        self.emissions = {}
        for line in transf:
            if len(line.strip()) == 0:
                continue
            tokens = line.split(" ")
            fromstate = tokens[0].strip()
            tostate = tokens[1].strip()
            prob = 0
            if len(tokens) > 2:
                prob = float(tokens[2])
            if fromstate not in self.transitions:
                self.transitions[fromstate] = {}
            self.transitions[fromstate][tostate] = prob
        transf.close()
            
        emitf = open(basename+ ".emit", "r")
        for line in emitf:
            if len(line.strip()) == 0:
                continue
            tokens = line.split(" ")
            state = tokens[0].strip()
            obs = tokens[1].strip()
            prob = 0
            if len(tokens) > 2:
                prob = float(tokens[2])
            if state not in self.emissions:
                self.emissions[state] = {}
            self.emissions[state][obs] = prob
        emitf.close()
        self.states = list(self.emissions.keys())
            
        
    # Write HMM to file
    # It writes out two files: one for the emissions (basename.emit) and
    # the other for the transitions (basename.trans)
    # Files are written line-by-line, with a separate transition or emission
    # probability on each line
    def dump(self, basename):
        transf = open(basename+ ".trans", "w+")
        for fromstate in self.transitions:
            for tostate in self.transitions[fromstate]:
                prob = self.transitions[fromstate][tostate]
                if prob is not None and prob > 0:
                    transf.write(fromstate + " " + tostate + " " + str(prob) + "\n")
        transf.close()

        emitf = open(basename+ ".emit", "w+")
        for state in self.emissions:
            for obs in self.emissions[state]:
                prob = self.emissions[state][obs]
                if prob is not None and prob > 0:
                    emitf.write(state + " " + obs + " " + str(prob) + "\n")
        emitf.close()

    # Given an observation, runs the forward algorithm
    # This should return the unnormalized forward beliefs,
    # aka alpha_i(t), in the form beliefs[t][i]
    def forward(self, observation):
        obs        = observation.asList()
        beliefs    = []

        for t in range(len(obs)):
            # Empty dictionary
            beliefs.append({}) 
            for s in self.states:
                beliefs[t][s]   = 0
                prevStates      = None 
                prevBeliefs     = None

                if t == 0:      
                    # Special start state
                    prevStates      = ['#']
                    prevBeliefs     = {'#': 1}
                else:           
                    prevStates      = self.states 
                    prevBeliefs     = beliefs[t-1]

                for prevS in prevStates:
                    prevB           = prevBeliefs[prevS]
                    # Transition, passage of time
                    beliefs[t][s]  += self.transitions[prevS][s] * prevB
                
                # Emission/observation stage
                obsProb         = self.emissions[s].get(obs[t], self.getUnkEmis(s))
                beliefs[t][s]  *= obsProb
        return beliefs

    # Computes the overall probability of the output sequence
    # using the forward algorithm.
    # This function is correct, do not change!
    def forward_probability(self, observation):
        t = len(observation)-1
        res = self.forward(observation)
        if res is None:
            return -1
        return sum(res[t].values())

    #Runs the viterbi algorithm on an observation
    # and returns a list of hidden states
    # indicating the most likely sequence given the model
    def viterbi(self, observation):
        ## Define variables
        # Observation list and dictionary for Viterbi probabilities
        obs       = observation.asList()
        Viterbi   = [{}]

        # Define the optimal path variables, I don't know if previous can be 0
        optPath  = []
        maxProb  = 0.0
        previous = None

        # Base case probabilities, 'prob' and 'prev' are easier to read on one line...
        for s in self.states:
            Viterbi[0][s] = {"prob":self.transitions['#'][s] * self.emissions[s].get(obs[0], self.getUnkEmis(s)),"prev": '#'}

        # Recursive for loop for probabilities
        for t in range(1, len(obs)):
            # Append empty dictionary
            Viterbi.append({})

            # Recursive loop for states in probability
            for s in self.states:
                # Calculate the probability of the transitionary state
                maxTransProb     = Viterbi[t-1][self.states[0]]["prob"]*self.transitions[self.states[0]][s]
                prevStSelected   = self.states[0]

                for prevSt in self.states[1:]:
                    transProb    = Viterbi[t-1][prevSt]["prob"]*self.transitions[prevSt][s]

                    # Replace the maximum transitional probability as needed
                    if transProb > maxTransProb:
                        maxTransProb     = transProb
                        prevStSelected   = prevSt

                # Calculate the maximum probability
                maxProb         = maxTransProb * self.emissions[s].get(obs[t], self.getUnkEmis(s))

                # Assign values to probability and previous
                Viterbi[t][s]   = {"prob": maxProb, "prev": prevStSelected}


        # Compute the optimal path from final state
        for st, data in Viterbi[-1].items():
            if data["prob"] > maxProb:
                maxProb  = data["prob"]
                bestSt   = st

        # Append best state to optimal path
        optPath.append(bestSt)
        previous         = bestSt

        # Follow backtrack to first observation
        for t in range(len(Viterbi)-2, -1, -1):
            optPath.insert(0, Viterbi[t+1][previous]["prev"])
            previous     = Viterbi[t+1][previous]["prev"]

        # Return Optimal Path
        return optPath
        
    # Given a corpus, consisting of observations labeled with known
    # states, learns the parameters of the HMM in a supervised fashion.
    #  Should use Lapace-style smoothing with a parameter of 0.01
    def learn_supervised(self, corpus):
        # Lapace-style smoothing value
        epsilon      = 0.01

        # Part 1: Count up transitions and emissions
        for obs in corpus:
            obsList       = obs.asList()
            stateList     = obs.getKnownState()

            # Configure initial states
            initialState = stateList[0]
            if initialState in self.transitions['#']:
                self.transitions['#'][initialState] += 1.0
            else:
                self.transitions['#'][initialState]  = 1.0

            '''
            # Add transitions
            for x, y in zip(stateList,stateList[1:]):
                if x in self.transitions:
                    if y in self.transitions[x]:
                        self.transitions[x][y] += 1.0
                    else:
                        self.transitions[x][y]  = 1.0

            # Add emissions
            for x, y in zip(stateList,obsList):
                if x in self.emissions:
                    if y in self.emissions[x]:
                        self.emissions[x][y] += 1.0
            '''

        # Unknown emissions
        for x in self.emissions:
             self.emissions[x]['UNKNOWN'] = 0

        # Part 2 Helper function
        # Define function to return the sum of items in a dictionary
        def returnDenomSum(myDict):
           sumVal        = 0.0
           for i in myDict:
               sumVal   += myDict[i]
           return sumVal

        # Part 2: Normalize transitions and emissions into probabilities
        # Normalize Transitions into probabilities
        for x in self.transitions:
            tDenom      = returnDenomSum(self.transitions[x]) + (len(self.transitions[x]) * epsilon)
            for y in self.transitions[x]:
                tNum    = self.transitions[x][y] + epsilon
                self.transitions[x][y]    = tNum / tDenom

        # Normalize Emissions into probabilities
        for x in self.emissions:
            eDenom      = returnDenomSum(self.emissions[x]) + ((len(self.emissions[x])) * epsilon)
            for y in self.emissions[x]:
                eNum    = self.emissions[x][y] + epsilon
                self.emissions[x][y]     = eNum / eDenom

                    # EXTRA CREDIT
    # Given an observation, runs the backward algorithm
    # This should return the unnormalized backwards beliefs,
    # aka beta_i(t), in the form beliefs[t][i]
    def backward(self, observation):
        obs = observation.asList()
        # YOUR CODE HERE
        pass #remove once implemented


    #Computes the overall probability of the output sequence
    # using the backward algorithm.
    # This function is correct, do not change!
    def backward_probability(self, observation):

        #Got to push backwards prob on time 0 back to initial state
        res = self.backward(observation)
        if res is None:
            return -1
        obs = observation.asList()
        finalRes = 0
        for s in res[0]:
            finalRes += res[0][s]* \
                self.transitions['#'][s]*self.emissions[s].get(obs[0],0)
        return finalRes
    
    # Runs the EM aka Baum Welch aka Forward-Backward algorithm
    # to learn the parameters of the HMM without any supervision.
    #
    # The data comes in a corpus, where each element of the corpus
    # is a sequence of type Observation.  Consider doing observation.asList()
    # to make these sequences easier to work with.
    #
    # The algorithm should stop when the log-likelihood changes by less than
    # 'convergence'.  It's probabaly a good idea to print out the log-likelihood
    # on each iteration so you can see what is going on.
    #
    # Should return the final log-likelihood of the entire corpus.
    #
    # Note: DO NOT initialize the parameters randomly, they should already be
    #    initialized to something when this method is called.
    def learn_unsupervised(self, corpus, convergence=0.069):
        # YOUR CODE HERE
        pass #remove once implemented
       
    
    #Is this HMM equal to another HMM, with some tolerance?
    def isEqual(self, other, tolerance):
        for i in self.transitions:
            if i not in other.transitions:
                print("Extra transition: " + str(i)) 
                return False
            for j in self.transitions[i]:
                if abs(self.transitions[i][j] - other.transitions[i].get(j,0)) > tolerance:
                    print("Transitions differ! " +i +" " + j +" "+ str(self.transitions[i][j]) + " " +str( other.transitions[i].get(j,0)))
                    return False
        for j in other.transitions:
            if j not in self.transitions:
                print("Missing transition: " + str(j)) 
                return False
        for i in self.emissions:
            if i not in other.emissions:
                print("Extra emission: " + str(i)) 
                return False
            for e in self.emissions[i]:
                if abs(self.emissions[i][e] - other.emissions[i].get(e,0)) > tolerance:
                    print("Emissions differ! " +i +" " + e +" "+ str(self.emissions[i][e]) + " " +str( other.emissions[i].get(e,0)))
                    return False
        for j in other.emissions:
            if j not in self.emissions:
                print("Missing emission: " + str(j)) 
                return False

        return True
        


    def plusEquals(self, dic, key, value):
        oldval = dic.get(key, 0)
        dic[key] = oldval + value

    
        
                
            

 
