from z3 import *

def generate(rows,cols,init,mines,goal,d):
    S = Solver()

    grid = [[Bool(f"cell_{i}_{j}") for j in range(cols)] for i in range(rows)]
    for i in range(rows):
        for j in range(cols):
            S.add(Or(grid[i][j], Not(grid[i][j])))

    print(S)


    return S

row,col = 3,3
init = [1,1]
mines = [2,1],[1,3]
goal = [3,3]
depth = 6

generate(row,col,init,mines,goal,d)