# Artificial Intelligence - Sliding Puzzle Solver

## Introduction

This repository contains a C++ implementation of an A* search algorithm to solve the sliding puzzle problem. The sliding puzzle problem involves a grid of numbered tiles with one empty space, and the goal is to rearrange the tiles from a given initial configuration to a specified goal configuration.

## Files

1. **ftnPuzzle.cpp**: Contains the implementation of the A* search algorithm and related functions.
2. **ftnPuzzle.h**: Header file defining the `State` class and function prototypes.
3. **main.cpp**: Main program file for running the sliding puzzle solver.
4. **Makefile**: Makefile for compiling the source code.

## Usage

To use this solver, follow these steps:

1. Compile the source code using the provided Makefile. Run `make` command in the terminal.

2. Run the compiled executable with the following command:
    ```bash
    ./ftnPuzzle
    ```

3. Enter the dimension of the matrix (e.g., 3 for a 3x3 puzzle) followed by the state of the puzzle. For Input Format:
    ```
    4
    2 3 6 4 1 5 0 7 10 11 12 8 9 13 14 15
    ```

4. If the goal configuration is found, the program will display it along with the number of iterations and the height of the solution path.

### Output:
```bash
Initial
2	3	6	4	
1	5	0	7	
10	11	12	8	
9	13	14	15	


Goal found!
1	2	3	4	
5	6	7	8	
9	10	11	12	
13	14	15	0	


Total no of Iterations: 60
Height: 15

Time: 0.002109 secs.
```

## Note

Ensure that you have a C++ compiler installed on your system to compile the source code.

