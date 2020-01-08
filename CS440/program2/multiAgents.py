# multiAgents.py
# --------------
# Licensing Information:  You are free to use or extend these projects for 
# educational purposes provided that (1) you do not distribute or publish 
# solutions, (2) you retain this notice, and (3) you provide clear 
# attribution to UC Berkeley, including a link to 
# http://inst.eecs.berkeley.edu/~cs188/pacman/pacman.html
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero 
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and 
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent

def scoreEvaluationFunction(currentGameState):
    """
      This default evaluation function just returns the score of the state.
      The score is the same one displayed in the Pacman GUI.

      This evaluation function is meant for use with adversarial search agents.
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
      This class provides some common elements to all of your
      multi-agent searchers.  Any methods defined here will be available
      to the MinimaxPacmanAgent & AlphaBetaPacmanAgent.

      You *do not* need to make any changes here, but you can if you want to
      add functionality to all your adversarial search agents.  Please do not
      remove anything, however.

      Note: this is an abstract class: one that should not be instantiated.  It's
      only partially specified, and designed to be extended.  Agent (game.py)
      is another abstract class.
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
      Your minimax agent (question 1)
    """
    def getAction(self, gameState):
          """
          Returns the minimax action from the current gameState using self.depth
          and self.evaluationFunction.

          Here are some method calls that might be useful when implementing minimax.

          gameState.getLegalActions(agentIndex):
            Returns a list of legal actions for an agent
            agentIndex=0 means Pacman, ghosts are >= 1

          gameState.generateSuccessor(agentIndex, action):
            Returns the successor game state after an agent takes an action

          gameState.getNumAgents():
            Returns the total number of agents in the game
          """
          (maxVal, maxAct) = self.getMax(gameState, 0) 
          return maxAct

    def getMin(self, gameState, depth, agent):
        if gameState.isWin() or gameState.isLose():
            return (self.evaluationFunction(gameState), None)

        # Two depths caused program to throw an exception...
        #depth          += 1
        minVal          = None
        minAct          = None
        # Only affected one ghost
        #playerIndex     = gameState.getNumAgents()-1

        for action in gameState.getLegalActions(agent):
            nextState                = gameState.generateSuccessor(agent, action)
            # If all ghosts have chosen a min, call getMax
            if (agent == gameState.getNumAgents() - 1):
                (val, subAction)     = self.getMax(nextState, depth)
                if minVal is None or val < minVal:
                    minVal           = val
                    minAct           = action 
            # If there are still ghosts to pick a getMin, call getMin
            else:
                (val, subAction) = self.getMin(nextState, depth, agent+1)
                if minVal is None or val < minVal:
                    minVal       = val
                    minAct       = action
        return (minVal, minAct)


    def getMax(self, gameState, depth):
        if gameState.isWin() or gameState.isLose():
            return (self.evaluationFunction(gameState), None)
        if depth == self.depth:  # if at the max depth
            return (self.evaluationFunction(gameState), None)

        depth          += 1
        maxVal          = None
        maxAct          = None
        playerIndex     = 0
        
        for action in gameState.getLegalActions(playerIndex):
            nextState            = gameState.generateSuccessor(playerIndex, action)
            (val, subAction)     = self.getMin(nextState, depth, 1)

            if maxVal is None or val > maxVal:
                maxVal    = val
                maxAct    = action
        return (maxVal, maxAct)


class AlphaBetaAgent(MultiAgentSearchAgent):
    """
      Your minimax agent with alpha-beta pruning (question 2)
    """

    # getMin/getMax agents with alpha/beta parameters added
    def getMin(self, gameState, depth, agent, alpha, beta):
        if gameState.isWin() or gameState.isLose():
            return (self.evaluationFunction(gameState), None)

        minVal          = None
        minAct          = None

        for action in gameState.getLegalActions(agent):
            nextState                = gameState.generateSuccessor(agent, action)
            # If all ghosts have chosen a min, call getMax
            if (agent == gameState.getNumAgents() - 1):
                (val, subAction)     = self.getMax(nextState, depth, alpha, beta)
                if minVal is None or val < minVal:
                    minVal           = val
                    minAct           = action 
                    # New code for Alpha/Beta pruning, strict inequality
                    if alpha is not None and minVal < alpha:
                        return minVal,minAct
                    if beta is None or beta > minVal:
                        beta = minVal
            # If there are still ghosts to pick a getMin, call getMin
            else:
                (val, subAction) = self.getMin(nextState, depth, agent+1, alpha, beta)
                if minVal is None or val < minVal:
                    minVal       = val
                    minAct       = action
                    # New code for Alpha/Beta pruning
                    if alpha is not None and minVal < alpha:
                        return (minVal,minAct)
                    if beta is None or beta > minVal:
                        beta     = minVal

        return (minVal, minAct)


    def getMax(self, gameState, depth, alpha, beta):
        if gameState.isWin() or gameState.isLose():
            return (self.evaluationFunction(gameState), None)
        if depth == self.depth:  # if at the max depth
            return (self.evaluationFunction(gameState), None)

        depth          += 1
        maxVal          = None
        maxAct          = None
        playerIndex     = 0
        
        for action in gameState.getLegalActions(playerIndex):
            nextState            = gameState.generateSuccessor(playerIndex, action)
            (val, subAction)     = self.getMin(nextState, depth, 1, alpha, beta)

            if maxVal is None or val > maxVal:
                maxVal    = val
                maxAct    = action

            # New code, uses the alpha beta values, strict equality
            if alpha is None or alpha < maxVal:
                alpha     = maxVal
            if beta is not None and maxVal > beta:
                return (maxVal, maxAct)
        return (maxVal, maxAct)

    def getAction(self, gameState):
        """
          Returns the minimax action using self.depth and self.evaluationFunction
        """
        "*** YOUR CODE HERE ***"

        # Initial attempt used infinite, remembered we aren't supposed to import other libraries...
        # Define alpha/beta
        # Infinity, since it's the initial value I see used most often
        # -math.inf/math.inf

        alpha    = None #-math.inf
        beta     = None #math.inf

        # Code from minimax, with alpha/beta minimax 
        (maxVal, maxAct) = self.getMax(gameState, 0, alpha, beta) 
        return maxAct


def betterEvaluationFunction(currentGameState):
    """
      Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
      evaluation function (question 3).

      DESCRIPTION: 
      First I take stock of my variables using the predefined functions
      These would be the gameState functions like getPacmanPosition(), 
      getFood(), getScore(), getGhostStates(), etc. By pulling as many 
      blackbox functions as possible I can pick a few values to test and 
      rule out a few ideas.

      These all get added to a score variable to function as a risk score. Like in
      Hearts, higher is worse. 

      I'd use the the food's position in conjunction with the Pacman's position
      in a Manhattan Distance function.
      I'd also use the same logic with the ghost's position. Since food and enemies
      will affect the risk/reward logic.

      Each of these go into a list to be added to a score variable. These lists
      get summed at the end. 

      I know I need to do somthing for the power pellets  as well, so I used them to lower
      the overall risk score. If a ghost has been eaten I pull the time that it spent in
      fear as well as the number of power pellets remaining

      Once all the values have been calculated and added to the score variable
      I return the score variable

      Attempt notes:
      I tried to keep track of eaten food, but it caused issues with timing. 
      I did this by creating a variable that made a list out of false instances of the
      foodList defined below. This didn't really work, and seemed to cause issues so I 
      removed it. 

      I used the reciprical of the food to make closer food more appealing, to skew the 
      risk.

    """
    "*** YOUR CODE HERE ***"

    
    # Instantiate score variable
    # 0 = Zero, NOT NULL!
    score     = 0

    # Will be used in 1/manhattanDistance, an attempt to lower the food risk
    foodDistancesRecip     = 0

    # Define variables using the predefined functions
    pacmanPosition    = currentGameState.getPacmanPosition()
    foodList          = currentGameState.getFood().asList()
    numCapsules       = len(currentGameState.getCapsules())
    ghostStates       = currentGameState.getGhostStates()

    # Put variables into form to add to score, usually with manhattanDistance
    
    # Food
    
    # Helper variables for food
    # Empty list to hold manhattan distance food
    foodDistances     = []

    # Calculate manhattan distance from each piece of food
    for i in foodList:
        foodDistances.append(manhattanDistance(pacmanPosition,i))

    # Ghosts pt. 1, ghost distance

    # Helper variables for Ghosts
    # Empty list to hold ghost position
    ghostPositions    = []
    
    # Empty list to hold manhanttan distance ghosts
    ghostDistances    = []

    # Add ghost positions to list
    for i in ghostStates:
        ghostPositions.append(i.getPosition())

    # Get manhattan distance from positions
    for i in ghostPositions:
        ghostDistances.append(manhattanDistance(pacmanPosition,i))

    # Calculate the times scared by capsule consumption
    # Empty list to hold the times scared
    scaredTimes = []

    # Append scared times to list
    for i in ghostStates:
        scaredTimes.append(i.scaredTimer)

    # Reciprocal to reduce the negative impact
    if sum(foodDistances) > 0:
        foodDistancesRecip    = 1.0/sum(foodDistances)

    # Add variables to score, summing current score, food distances, and eaten food
    score         += currentGameState.getScore() + foodDistancesRecip

    # Capsule conditional, if ghosts have been scared lower score
    if sum(scaredTimes) > 0:
        score     += sum(scaredTimes) - numCapsules - sum(ghostDistances)
    # Ghosts have never been scared, increase score by distance and ghosts remaining
    else:
        score     += sum(ghostDistances) + numCapsules

    # Return score
    return score

# Abbreviation
better = betterEvaluationFunction

