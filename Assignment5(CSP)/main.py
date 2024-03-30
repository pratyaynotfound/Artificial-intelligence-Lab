from csp import *

n = int(input("Enter the number of queens in the chessboard:")) 

#represent the n-queens problem as a csp
nqueens = NQueensCSP(n)

# Implement the min-conflicts algorithm that returns the solution.
# Recall that min-conflicts algorithm is a local search algorithm
# with 'min-conflicts' value selection heuristic. The algorithm
# can solve (with a high probability) millions of queens problem 
# instances efficiently.
 
assignment = min_conflicts(nqueens)

#if solution found, print it.
if assignment is not None:
    for row in range(n):
        line = ""
        for col in range(n):
            if assignment[col] == row:
                line += "Q "
            else:
                line += ". "
        print(line)
else:
    print("No solution found within the given number of steps.")