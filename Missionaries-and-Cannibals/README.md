# Assignment Problem 2: Missionaries and Cannibals Problem


## Problem Description

The missionaries and cannibals problem is usually stated as follows. Three missionaries and three cannibals are on one side of a river, along with a boat that can hold one or two people. Find a way to get everyone to the other side without ever leaving a group of missionaries in one place outnumbered by the cannibals in that place. This problem is famous in AI because it was the subject of the first paper that approached problem formulation from an analytical viewpoint (Amarel, 1968).
## Questions:
1. Formulate the problem precisely, making only those distinctions necessary to ensure a valid solution. Draw a diagram of the complete state space.
2. Implement and solve the problem optimally using an appropriate search algorithm. Is it a good idea to check for repeated states?
3. Why do you think people have a hard time solving this puzzle, given that the state space is so simple?

##  Solution:
### Problem 1:
> ### Formulate the problem precisely, making only those distinctions necessary to ensure a valid solution. Draw a diagram of the complete state space.


### Problem 2:
> ### Implement and solve the problem optimally using an appropriate search algorithm. Is it a good idea to check for repeated states?

Here is the solution for [Missionaries and Cannibals Problem](main.cpp).

### Output
- M: Number of missionaries on the left side of the river.
- C: Number of cannibals on the left side of the river.
- B: Boat position (B is boat is present, for the left tuple if there is B then boat is on the left side and if blank then the boat is on the right side and and for the right side vise versa).

A state can be represented as a tuple (M, C, B).

Actions:
(m, c): Move m missionaries and c cannibals across the river.

Output is given as below.
```bash
Initial State: 
(3, 3, B) (0, 0,  ) Level: 0
(2, 2,  ) (1, 1, B) Level: 1
(2, 3,  ) (1, 0, B) Level: 1
(1, 3,  ) (2, 0, B) Level: 1
(2, 3, B) (1, 0,  ) Level: 2
(0, 3,  ) (3, 0, B) Level: 3
(1, 3, B) (2, 0,  ) Level: 4
(1, 1,  ) (2, 2, B) Level: 5
(2, 2, B) (1, 1,  ) Level: 6
(2, 0,  ) (1, 3, B) Level: 7
(3, 0, B) (0, 3,  ) Level: 8
(1, 0,  ) (2, 3, B) Level: 9
(1, 1, B) (2, 2,  ) Level: 10
(2, 0, B) (1, 3,  ) Level: 10
(0, 0,  ) (3, 3, B) Level: 11
(0, 0,  ) (3, 3, B) Level: 12
Goal state found!
Total moves: 11
```

### Problem 3:
> ### Why do you think people have a hard time solving this puzzle, given that the state space is so simple?

In my opinion, the problem is not difficult to solve. When I finally understood the state space representation, which had been confusing me, the task became simple for me.

