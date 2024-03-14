# Importing itertools module to use combinations function
from itertools import combinations

# Global variables
global MC   #cost matrix
global CC   #cost of inserting dash
global V    #vocabulary
global n    #elngth of the max string
global k    #total no of strings

# State class definition
class State: 
    def __init__(self, strings, col_cost, total_cost, col, parent, h_val=None):
        # Initializing state attributes
        self.strings = strings
        self.col_cost = col_cost
        self.total_cost = total_cost
        self.col = col
        self.parent = parent
        self.h_val = h_val
    
    def generate_col_str(self, col):
        # Generate a string consisting of characters from the col-th column of each string
        l = []
        for s in self.strings:
            l.append(s[col:col+1])
        return "".join(l)

    def calc_total_cost(self):
        # Calculate the total cost of the state
        cost1 = 0
        cost2 = 0
        for s in self.strings:
            k = s.count("-")
            cost1 += (k * CC)
        for i in range(n):
            cost2 += self.calc_col_cost(self.generate_col_str(i))
        return cost1 + cost2
    
    def put_dashes(self, col, s):
        # Insert dashes into the strings at the specified column
        new_strs = []
        for i in range(len(self.strings)):
            if s[i] == '-':
                new_strs.append(self.strings[i][:col+1] + '-' + self.strings[i][col+1:])
            else:
                new_strs.append(self.strings[i])
        return new_strs
    
    def is_goal(self):
        # Check if the current column is the last column(goal state)
        if self.col == n - 1:
            return True 
        else:
            return False
    
    def check_all_length(self):
        # Check if all strings have length equal to n
        if all(len(s) == n for s in self.strings):
            return True
        else:
            return False
        
    def calc_col_cost(self, s):
        # Calculate the column-wise sorting cost for a given string s
        col_cost = 0
        for i in range(len(s) - 1):
            col_cost += MC[(s[i:i+1]), s[i+1:i+2]]
        col_cost += MC[(s[-1]), s[0:1]]
        return col_cost
        
    
    def gen_children(self, col):
        # Generate child states by considering all possible combinations of dashes in the col-th column
        childs = []
        new_states = []

        col_str = self.generate_col_str(col)
        if all(len(s) > col for s in self.strings):
            for num_dashes in range(len(self.strings) + 1):
                for dashes in combinations(range(len(self.strings)), num_dashes):
                    new_col_str = list(col_str)

                    for dash in dashes:
                        new_col_str[dash] = "-"
                    childs.append(''.join(new_col_str))

            if '-' * k in childs:
                childs.remove('-' * k)
            for s in childs:
                temp_str = self.put_dashes(col, s)
                if all(len(s) <= n for s in temp_str):
                    new_states.append(State(temp_str, self.calc_col_cost(s), self.total_cost + self.calc_col_cost(s), col + 1, None))

        return new_states
    
    def calc_h_val(self):
        # Calculate the heuristic value of the state
        h = self.total_cost
        for s in self.strings:
            k = s.count("-")
            h += (k * CC)
        return h

    
# Branch and Bound search function
def search_bnb(strings):
    # Initialize variables
    visited = set()
    init_state = State(strings, col_cost=0, total_cost=0, col=0, parent=None)
    fronteir = [init_state]
    c_list = set()
    best_sol = State(strings, 100000000, 100000000, 0, None, 100000000)

    while fronteir:
        current_state = fronteir.pop()

        # Check if goal state or all strings have reached desired length
        if current_state.is_goal() or current_state.check_all_length():
            if current_state.check_all_length() == True:
                current_state.h_val = current_state.calc_total_cost()
            if current_state.total_cost == 0 or current_state.h_val < best_sol.h_val:
                best_sol = current_state
            else:
                continue
        else:
            children = current_state.gen_children(current_state.col)
            for child in children:
                if child not in visited:
                    child.parent = current_state
                    child.h_val = child.calc_h_val()
                    fronteir.append(child)
            fronteir.sort(key=lambda x:x.h_val)
            c_list.add(current_state)
    return best_sol

# Initialize global variables
MC = {}
CC = 0
V = []

# Read input from file and initialize variables
with open("/Users/pratyaysarkar/Library/CloudStorage/OneDrive-Personal/AI/Artificial-intelligence-Lab/Search/input.txt", "r") as f:
    skip_line = float(f.readline().strip())
    V = f.readline().strip().split(', ')
    k = int(f.readline().strip())
    X = [f.readline().strip() for i in range(k)]
    CC = int(f.readline().strip())
    for i in range(len(V)):
        temp=f.readline().split()
        for j in range(i,len(V)):
            MC[(V[i],V[j])] = MC[(V[j],V[i])]= int(temp[j])
        MC[(V[i],'-')]=MC[('-',V[i])]=int(temp[j])
    temp=f.readline().split()
    MC[('-', '-')] = int(temp[-1])

n = max([len(x) for x in X])

# Perform Branch and Bound search
state = search_bnb(X)
print("Cost:", state.h_val)

for i in state.strings:
    print(i+'\n')

