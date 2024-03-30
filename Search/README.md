GeneString.py
==============

The GeneString.py script is designed to solve a genetic string optimization problem using a branch and bound search algorithm. Below is an overview of the script and its functionalities.

Functionality Overview
----------------------

The script defines a State class representing a state in the search space and provides functions for generating children states, calculating costs, and evaluating heuristic values. It also includes a branch and bound search function to find the optimal solution.

Key Components
---------------

- `State` class:
  - Represents a state in the search space.
  - Includes methods for generating child states, calculating costs, and evaluating heuristic values.

- `search_bnb` function:
  - Performs a branch and bound search to find the optimal solution.

Global Variables
-----------------

- `MC`: Cost matrix representing the cost of substituting characters.
- `CC`: Cost of inserting a dash.
- `V`: Vocabulary of characters.
- `n`: Length of the maximum string.
- `k`: Total number of strings.

Usage
-----

To use the GeneString.py script, follow these steps:

1. Ensure that the required input data is provided in the `input.txt` file.
2. Run the script using the following command:

```bash
python3 GeneString.py
```


3. The script will output the cost and the optimized strings.

Example Input (input.txt)
--------------------------

```bash
5
A, C, T, G
3
ACTGTGA
TACTGC
ACTGA
3
0 2 2 2 1
2 0 2 2 1
2 2 0 2 1
2 2 2 0 1
1 1 1 1 0
```


Example Output
--------------

```bash
Cost: 27
ACTGTGA

TAC-TGC

AC--TGA

```
