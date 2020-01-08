# CS 440 Multi-Armed Bandit Assignment
# (C) 2017 Travis Mandel

#These imports should be sufficient
import random
import math
import environments as envs
import distributions as dists

# Interface (abstract) for multiarmed bandit learners
# Don't change this
class MABLearner(object):

    # Re-initializes the MAB with a given MABEnvironment
    # Returns True if initialization was successful, False otherwise
    def initWithEnvironment(self,env):
        pass

    #Chooses an arm to pull based on all the rewards processed so far
    # Arms are represented as integers, so it just needs to return a
    # number between 0 and the number of arms in the environment
    def chooseArm(self):
        pass

    #Processes a reward
    def processReward(self, arm, reward):
        pass


# Implements the epsilon-greedy algorithm as discussed in class
class EpsilonGreedy(MABLearner):

    def __init__(self, epsilon):
        self.epsilon = epsilon

    def initWithEnvironment(self,env):
        self.env          = env
        self.armTotals    = []
        self.armCounts    = []

        for arm in range(self.env.getNumArms()):
            self.armTotals.append(0)
            self.armCounts.append(0)
        return True #Change to return True once implemented

    def chooseArm(self):
        # Pick a random number for baby epsilon
        if random.random() < self.epsilon:
            return random.randrange(self.env.getNumArms())

        maxArm       = None
        maxReward    = None

        for arm in range(self.env.getNumArms()):
            if self.armCounts[arm] ==0:
                continue
            meanR    = self.armTotals[arm]/self.armCounts[arm]
            if maxReward is None or meanR > maxReward:
                maxArm       = arm
                maxReward    = meanR

        if maxArm is None:
            return random.randrange(self.env.getNumArms())

        return maxArm 

    def processReward(self,arm, reward):
        self.armTotals[arm] += reward
        self.armCounts[arm] += 1

# Implements the UCB algorithm as discussed in class
class UCB(MABLearner):

    def __init__(self, alpha):
       self.alpha         = alpha

    def initWithEnvironment(self,env):
        # Instantiate variables
        self.env          = env
        self.armTotals    = []
        self.armCounts    = []
        
        # Assign initial values, should it be NONE?
        for arm in range(self.env.getNumArms()):
            self.armTotals.append(0)
            self.armCounts.append(0)

        return True 

    def chooseArm(self):
        # Instantiate variables
        maxArm       = None
        maxCon       = None
        totalRewards = 0

        # Check if arm has been pulled
        for arm in range(self.env.getNumArms()):
            if self.armCounts[arm] == 0:
                return arm

        # Check arms for maxArm value
        for arm in range(self.env.getNumArms()):
            meanR                = self.armTotals[arm] / self.armCounts[arm]       

            # Count rewards recieved
            for count in self.armCounts:
                totalRewards    += count

            # Apply formula from slides to get confidence bound
            currCon       = meanR + math.sqrt((2 * math.log(totalRewards))/self.armCounts[arm])

            # Choose max arm and confidence
            if maxCon == None or currCon > maxCon:
                maxArm    = arm
                maxCon    = currCon

        return maxArm

    def processReward(self,arm, reward):
        reward               = (reward - self.env.getMinReward())/(self.env.getMaxReward() - self.env.getMinReward())
        self.armTotals[arm] += reward 
        self.armCounts[arm] += 1

# Implements the Beta-Bernoulli thompson sampling algorithm as discussed
#in class.
#Should handle the straightforward extension to non-discrete variables.
class ThompsonDiscrete(MABLearner):

    def __init__(self):
        pass # Remove once implemented
        # Leaving it alone
        
    def initWithEnvironment(self,env):
        # Instantiate variables
        self.env         = env
        self.armDist     = []
        self.armCount    = []

        # Append initial Beta-Bernoulli Distribution and count
        for arm in range(self.env.getNumArms()):
            self.armDist.append(dists.BetaDistribution(1,1))
            self.armCount.append(0)

        return True

    def chooseArm(self):
       # Define arm with best reward and best reward
       maxArm        = None
       maxReward     = None

       # Sample arms to look for best reward
       for arm in range(self.env.getNumArms()):
           reward    = self.armDist[arm].sample()

           # Decide if reward is the maximum possible Reward
           if maxReward is None or reward > maxReward:
               maxReward    = reward
               maxArm       = arm

       return maxArm 

    def processReward(self, arm, reward):
        reward       = (reward - self.env.getMinReward())/(self.env.getMaxReward() - self.env.getMinReward())

        # Non-zero rewards, use probability to choose 1 or 0
        if reward != 1 and reward != 0:
            if random.random() < reward:
                reward      = 1
            else:
                reward      = 0

        # Increase Alpha
        if reward == 1:
            self.armDist[arm].alpha    += 1

        # Increase Beta, reware == 0
        else:
            self.armDist[arm].beta     += 1
