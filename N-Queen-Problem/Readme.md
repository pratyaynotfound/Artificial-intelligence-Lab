# Assignment Problem 1: N-Queens Problem


## Problem Description

Write a program to solve the 8-queens problem. The goal of the 8-queens problem is to place eight queens on a 8 x 8 chessboard such that no queen attacks any other. The problem formulation in terms of the state-space is as follows:
1. State: An arrangement of 0-8 queens such that each column has at most one queen.
2. Initial State: No queens on the board.
3. Action: Add a queen to any empty column.
4. Transition function: Returns the board(s) with a queen added to the specified column.
5. Goal test: 8 queens are on the board, none attacked.
### Write a program to:
1. Solve the problem by search, starting from the initial state. Print the solution chessboard when found.
2. Print the number of solutions to the problem.
3. Generalize your program to solve n queens problem. What is the maximum n that your program can solve in reasonable time (less than 30 mins).


## Questions:
### Problem 1:
> ### Solve the problem by search, starting from the initial state. Print the solution chessboard when found.
### Solution:
Here is the solution for [N-Queens Problem](N-Queen.cpp).

### Problem 2:
> ### Print the number of solutions to the problem.

### Output
Output is given as below.
```bash
0 Q 0 0 
0 0 0 Q 
Q 0 0 0 
0 0 Q 0 

0 0 Q 0 
Q 0 0 0 
0 0 0 Q 
0 Q 0 0 

=================================
4-Queen Solutions:
Total no of solutions: 2
Total time taken: 6.3e-05 Sec
=================================
```
### Problem 3:
> ### Generalize your program to solve n queens problem. What is the maximum n that your program can solve in reasonable time (less than 30 mins).


### The maximum n that my program can solve in 30 mins is 16.
- In this case of 16, I have not included the print solution.

Here is the output for 16-Queens.
```bash
=================================
16-Queen Solutions:
Total no of solutions: 14772512
Total time taken: 407.667 Sec
=================================
```