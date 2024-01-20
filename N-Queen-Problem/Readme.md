# Assignment 1: N-Queens Problem

Welcome to the N-Queens Problem folder! This section contains the solution, benchmarks, and detailed documentation for the N-Queens problem as part of the COM 4211 - Artificial Intelligence Lab course.

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

### Solution:
Here is the solution for [N-Queens Problem](N-Queen-Problem/N-Queen.cpp)

## Output
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
