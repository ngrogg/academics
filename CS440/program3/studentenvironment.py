# CS 440 Multi-Armed Bandit Assignment
# (C) 2017 Travis Mandel

#These imports should be sufficient
import random
import math
import distributions as dists
import environments as envs

# I think the statement below is a typo, since the answer graphs show UCB-0.01 matching or outperforming UCB-1
# And the assignemnt word doc states the opposite...

#Write a comment explaining why UCB-1 must always be better than UCB-0.01, or
# a comment explaining your counterexample environment

"""
   UCB-0.01 outperforms UCB-1 because it has a smaller alpha value and a stricter confidence bound. 
   This causes UCB-0.01 to be more discerning with arm rewards than UCB-1 and less tolerant with unfavorable rewards.

"""

class StudentEnv(envs.MABEnvironment):
    def __init__(self):
        #YOUR CODE HERE
        pass #remove once implemented

    def pull(self,arm):
        #YOUR CODE HERE
        pass #remove once implemented

    def reset(self):
        #YOUR CODE HERE
        return False #Change to return True once implemented
    
    def getNumArms(self):
        #YOUR CODE HERE
        pass #remove once implemented
 
    def getMinReward(self):
        #YOUR CODE HERE
        pass #remove once implemented
		
    def getMaxReward(self):
        #YOUR CODE HERE
        pass #remove once implemented
