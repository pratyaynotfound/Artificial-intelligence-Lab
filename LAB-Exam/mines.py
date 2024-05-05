import z3

solver = z3.Solver()

def check_for_bound(move, n):
    x, y = move
    return 0 <= x < n and 0 <= y < n

def generate_moves(move, n):
    moves = [(move[0] - 1, move[1]), (move[0], move[1] - 1), (move[0], move[1] + 1)]
    right_moves = [move for move in moves if check_for_bound(move, n)]
    return right_moves

def generate_constraints(init, mines, goal, n, depth):
    # Initial position constraint
    solver.add(z3.Bool(f"{init[0]}_{init[1]}_0"))  # Using the format (x_y_depth)

    # Mines constraint
    for k in range(depth):
        for mine in mines:
            solver.add(z3.Not(z3.Bool(f"{mine[0]}_{mine[1]}_{k}")))

    for k in range(1,depth+1):
        for i in range(n):
            for j in range(n):
                move = (i, j)
                moves = generate_moves(move, n)
                for new_move in moves:
                    # Add implication: if current cell is true, then one of the valid moves must be true
                    solver.add(z3.Implies(z3.Bool(f"{i}_{j}_{k}"), z3.Bool(f"{new_move[0]}_{new_move[1]}_{k+1}")))

    for k in range(depth+1):
        for i in range(n):
            for j in range(n):
                for l in range(n):
                    for m in range(n):
                        if l!=i and m!=j:
                            solver.add(z3.Implies(z3.Bool(f"{i}_{j}_{k}"), z3.Not(z3.Bool(f"{l}_{m}_{k}"))))

    # Goal position constraint
    solver.add(z3.Bool(f"{goal[0]}_{goal[1]}_{depth}"))

    return solver.to_smt2()


# Define problem parameters
init = (0, 0)  # Initial position
mines = [(1, 0), (2, 1)]  # Positions of mines
goal = (2, 2)  # Goal position
n = 3  # Grid size
depth = 4  # Maximum depth for additional constraints

# Generate SMT2
smt2_content = generate_constraints(init, mines, goal, n, depth)

# Save SMT2 to a file
if smt2_content:
    with open("constraints.smt2", "w") as f:
        f.write(smt2_content)

print(solver.check())
if solver.check() == z3.sat:
    print(solver.model())