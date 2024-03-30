## N-Queens Problem Solver using Min-Conflicts Algorithm

This repository contains Python code to solve the N-Queens problem using the min-conflicts algorithm, a local search algorithm with a 'min-conflicts' value selection heuristic. The min-conflicts algorithm efficiently solves N-Queens problems with a high probability.

### Files Included
1. **main.py**: This file contains the main code to solve the N-Queens problem. It prompts the user to enter the number of queens on the chessboard, represents the problem as a Constraint Satisfaction Problem (CSP), and then uses the `min_conflicts` function to find a solution. If a solution is found, it prints the solution on the console.

2. **utils.py**: This file contains various utility functions used by other modules. These functions include utilities for sequences and iterables, statistical and mathematical functions, grid functions, miscellaneous functions, expressions handling, queues, and useful shorthands.

### Usage
1. Clone the repository to your local machine.
2. Run the `main.py` file using a Python interpreter.
3. Enter the number of queens on the chessboard when prompted.
4. View the solution printed on the console.

### Example Output
```bash
Enter the number of queens in the chessboard: 8
Q . . . . . . .
. . . . Q . . .
. . . . . . . Q
. . . . . Q . .
. . Q . . . . .
. . . . . . Q .
. Q . . . . . .
. . . Q . . . .
```
