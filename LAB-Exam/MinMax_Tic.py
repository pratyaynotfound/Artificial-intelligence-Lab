
player, opponent = 'x','o'

#   This is the function for checking if the current board has any spaces left
def isMoveLeft(board):
    for i in range(3):
        for j in range(3):
            if board[i][j] == '_':
                return True
    return False

#    This function tells us is the current state of the board is in a terminal state
def isGoal(board,player):
    #    This portion of the code checks if any row is in terminal state
    for row in range(3):
        if board[row][0] == board[row][1] and board[row][1] == board[row][2]:
            if  board[row][0] == player:
                return +10
            if board[row][0] == opponent:
                return -10
            
    #   This portion of the code checks if any column of the board is in terminal state
    for col in range(3):
        if board[0][col] == board[1][col] and board[1][col] == board[2][col]:
            if  board[0][col] == player:
                return +10
            if board[0][col] == opponent:
                return -10
            
    #   Now we have to check the diagonals
    if board[0][0] == board[1][1] and board[1][1] == board[2][2]:
        if  board[0][0] == player:
            return +10
        elif board[0][0] == opponent:
            return -10
        
    if board[0][2] == board[1][1] and board[1][1] == board[2][0]:
        if  board[0][2] == player:
            return +10
        elif board[0][2] == opponent:
            return -10

#   This is the function for the minmax algorithm
def minimax(board, depth, isMaximizing):
    #    If the computer wins thats the best possible case then it is +infinity
    if isGoal(board,'x'):
        return float('inf')
    
    #   If the Opponent wins thats the worst possible case then that is -infinity
    elif isGoal(board,'o'):
        return float('-inf')
    
    elif not isMoveLeft(board):
        return 0
    
    #    Now there is the moves for maximizing and minimizing players
    if isMaximizing:
        best_score = -1000 #    For maximizing player we want the max possible move thats why it is initialized to -1000

        for row in range(3):
            for col in range(3):
                if board == '_':
                    board[row][col] = player

                    best_score = max(best_score,minimax(board, depth+1,not isMaximizing))

                    board[row][col] = '_'
                
        return best_score
    
    else:
        best = 1000 #    For minimizing player we want the min possible move thats why it is initialized to 1000

        for row in range(3):
            for col in range(3):
                if board[row][col] == '_':
                    board[row][col] == opponent

                    best = min(best, minimax(board,depth+1,not isMaximizing))

                    board[row][col] = '_'
        return best

def find_best(board):
    best_val = -1000
    best_move = (-1,-1)

    for i in range(3):
        for j in range(3):
            if board[i][j] == '_':
                board[i][j] = player

                move_val = minimax(board,0,False)

                board[i][j] = '_'

                if move_val > best_val:
                    best_move = (i,j)
                    best_val = move_val

    print("The value of the best Move is :", best_val) 
    print() 
    return best_move 

# This is the initial board configuration
board = [ 
    [ 'x', 'o', 'x' ],  
    [ 'o', 'o', 'x' ],  
    [ '_', '_', '_' ]  
]

bestMove = find_best(board)
print("The Optimal Move is :")  
print("ROW:", bestMove[0], " COL:", bestMove[1])