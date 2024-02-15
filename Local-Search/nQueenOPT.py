import numpy as np
from search import *


class __nQueen__(Problem):
    def __init__(self,N):
        self.N = N
        initial = tuple(np.random.permutation(N))
        super().__init__(initial,goal=None)
    
    def actions(self,state):
        actions = []
        for i in range(self.N):
            for j in range(i+1,self.N):
                actions.append((i,j))
            
        return actions
    
    def result(self,state,action):
        state = list(state)
        i,j = action
        state[i],state[j] = state[j],state[i]
        return tuple(state)
    
    def value(self,state):
        non_attacking = 0
        for i in range(self.N):
            for j in range(i+1,self.N):
                if state[i] != state[j] and abs(state[i] - state[j]) != j-i:
                    non_attacking += 1
                
        return non_attacking
