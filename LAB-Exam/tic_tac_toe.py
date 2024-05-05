import sys
import pygame 
import numpy as np

pygame.init()

#Colors
WHITE = (225,225,225)
RED = (225,0,0)
GRAY = (180,180,180)
GREEN = (0,225,0)
BLACK = (0,0,0)

# Sizes

WIDTH = 300
HEIGHT = 300
LINE_WIDTH = 5
BROWS = 3
BCOLS = 3
SQR_SIZE = WIDTH // BROWS
CIRCLE_RAD = SQR_SIZE // 3
CIRCLE_WIDTH = 15
CROSS_WIDTH = 25

screen = pygame.display.set_mode((WIDTH,HEIGHT))
pygame.display.set_caption('Tic Tac Toe Minmax')

screen.fill(BLACK)

board = np.zeros((BROWS,BCOLS))

def draw_lines(color=WHITE):
    for i in range(1,BROWS):
        pygame.draw.line(screen, color, (0, SQR_SIZE*i),(WIDTH, SQR_SIZE*i),LINE_WIDTH)
        pygame.draw.line(screen, color, (SQR_SIZE*i,0),(SQR_SIZE*i,HEIGHT),LINE_WIDTH)

def draw_figs(color = WHITE):
    for row in range(BROWS):
        for col in range(BCOLS):
            if board[row][col] == 1:
                pygame.draw.circle(screen, color, (int(col*SQR_SIZE+SQR_SIZE//2),int(row*SQR_SIZE+SQR_SIZE//2)),CIRCLE_RAD,CIRCLE_WIDTH)
            
            elif board[row][col] == 2:
                pygame.draw.line(screen,color,(col*SQR_SIZE+SQR_SIZE//4,row*SQR_SIZE+SQR_SIZE//4), (col*SQR_SIZE+3*SQR_SIZE//4,row*SQR_SIZE+3*SQR_SIZE//4),CROSS_WIDTH)
                pygame.draw.line(screen,color,(col*SQR_SIZE+SQR_SIZE//4,row*SQR_SIZE+3*SQR_SIZE//4), (col*SQR_SIZE+3*SQR_SIZE//4,row*SQR_SIZE+SQR_SIZE//4),CROSS_WIDTH)


def mark_sqr(row,col,player):
    board[row][col] = player

def available_sqr(row,col):
    return board[row][col] == 0

def is_board_full(check_board = board):
    for row in range(BROWS):
        for col in range(BCOLS):
            if check_board[row][col] == 0:
                return False
    
    return True

def check_win(player,check_board = board):
    for col in range(BCOLS):
        if check_board[0][col] == player and check_board[1][col] == player and check_board[2][col] == player:
            return True
        
    for row in range(BROWS):
        if check_board[row][0] == player and check_board[row][1] == player and check_board[row][2] == player:
            return True
        
    if check_board[0][0] == player and check_board[1][1] == player and check_board[2][2] == player:
        return True
    
    if check_board[2][0] == player and check_board[1][1] == player and check_board[2][0] == player:
        return True
    
    return False

def minmax(minmax_board,depth,is_maximizing):
    if check_win(2, minmax_board):
        return  float('inf')
    
    elif check_win(1,minmax_board):
        return float('-inf')

    elif is_board_full(minmax_board):
        return 0
    
    if is_maximizing:
        best_score = -1000
        for row in range(BROWS):
            for col in range(BCOLS):
                if minmax_board[row][col] == 0:
                    minmax_board[row][col] = 2
                    score = minmax(minmax_board,depth+1,False)
                    minmax_board[row][col] = 0
                    best_score = max(score, best_score)
        return best_score
    else:
        best_score = 1000
        for row in range(BROWS):
            for col in range(BCOLS):
                if minmax_board[row][col] == 0:
                    minmax_board[row][col] = 1
                    score = minmax(minmax_board,depth+1,True)
                    minmax_board[row][col] = 0
                    best_score = min(score, best_score)
        return best_score

def best_move():
    best_score = -1000
    move = (-1,-1)
    for row in range(BROWS):
        for col in range(BCOLS):
            if board[row][col] == 0:
                board[row][col] = 2
                score = minmax(board,0,False)
                board[row][col] = 0

                if score > best_score:
                    best_score = score
                    move = (row,col)

    if move != (-1,-1):
        mark_sqr(move[0],move[1],2)
        return True
    return False

def restart_game():
    screen.fill(BLACK)
    draw_lines()
    for row in range(BROWS):
        for col in range(BCOLS):
            board[row][col] = 0


draw_lines()
player = 1
game_over = False


while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()

        if event.type == pygame.MOUSEBUTTONDOWN and not game_over:
            mouseX = event.pos[0] // SQR_SIZE
            mouseY = event.pos[1] // SQR_SIZE

            if available_sqr(mouseY,mouseX):
                mark_sqr(mouseY,mouseX,player)
                if check_win(player):
                    game_over = True

                player = player%2 + 1 

                # Check if it's the computer's turn
                if player == 2 and not game_over:
                    if best_move():
                        if check_win(2):
                            game_over = True
                        player = player%2 + 1 

            if not game_over:
                if is_board_full():
                    game_over = True

        
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_r:
                restart_game()
                game_over = False

    if not game_over:
        draw_figs()
    else:
        if check_win(1):
            draw_figs(GREEN)
            draw_lines(GREEN)
        
        elif check_win(2):
            draw_figs(RED)
            draw_lines(RED)
        
        else:
            draw_figs(GRAY)
            draw_lines(GRAY)

    pygame.display.update()
