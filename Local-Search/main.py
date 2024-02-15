from search import hill_climbing
from nQueenOPT import __nQueen__



N = int(input("Enter the number of queens:"))

problem = __nQueen__(N)
solution = hill_climbing(problem)

for i in range(N):
    row = ["."] * N
    row[solution[i]] = "Q"
    print(" ".join(row))

print("Value:", problem.value(solution))