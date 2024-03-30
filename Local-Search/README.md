N Queen Optimization Problem 
=========

The nQueenopt project is designed to solve the N-Queens problem using optimization techniques. This README provides an overview of the project structure and functionality.

Project Structure
-----------------

- `main.py`: The main script to run the N-Queens optimization solver.
- `utils.py`: Provides utility functions widely used by other modules.
- `search.py`: Contains search algorithms and related functions.
- `nQueenOPT.py`: Implements the N-Queens optimization solver.

How to Run
----------

To run the N-Queens optimization solver, execute `main.py`:

```bash
python3 main.py
```


This will start the solver and display the solution.

Modules Overview
----------------

1. `utils.py`:
   - Provides utility functions for sequences, statistical and mathematical operations, grid functions, miscellaneous functions, and queues.

2. `search.py`:
   - Contains search algorithms such as hill climbing and simulated annealing.
   - Implements functions for evaluating board states and generating neighbor states.

3. `nQueenOPT.py`:
   - Implements the N-Queens optimization solver using hill climbing and simulated annealing techniques.
   - Provides functions for initializing the board, calculating fitness, and optimizing the board layout.

Example Usage
-------------

Here's an example of how to use the N-Queens optimization solver in your code:

```python
# Import the solver
from nQueenOPT import NQueensOptimizationSolver

# Create an instance of the solver
solver = NQueensOptimizationSolver(board_size=8)

# Solve the N-Queens problem
solution = solver.solve()

# Print the solution
print("Solution:", solution)
