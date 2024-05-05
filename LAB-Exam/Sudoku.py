def is_valid_move(grid,row,col,number):
    #first we check for if the row contains 2 same numbers
    for x in range(9):
        if grid[x][col] == number:
            return False
    
    # Now we check for if the column conatins 2 same numbers
    for i in range(9):
        if grid[row][i] == number:
            return False
        
    corner_row = row - row%3
    corner_col = col - col%3

    #Now we have to check the 3x3 block
    for i in range(3):
        for j in range(3):
            if grid[corner_row+i][corner_col+j] == number:
                return False
            
    return True

def solve(grid,row,col):
    #base case
    if col == 9:
        if row == 8:
            return True # already solved
        row += 1    # go to the next row
        col = 0 # go to the first column

    #the cell we are currently at is greater than 0 then we are going to solve for col+1
    if grid[row][col] > 0:
        return solve(grid,row,col+1)
    
    # for all indevidual possibilities
    for num in range(1,10):
        if is_valid_move(grid,row,col,num):
            grid[row][col] = num

            if solve(grid,row,col+1):
                return True
            
        grid[row][col] = 0
    return False

grid = [
[4, 0, 6, 0, 0, 5, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 1, 9, 8],
[3, 0, 0, 0, 8, 2, 4, 0, 0],
[0, 0, 0, 1, 0, 0, 0, 8, 0],
[9, 0, 3, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 3, 0, 6, 7, 0],
[0, 5, 0, 0, 0, 9, 0, 0, 0],
[0, 0, 0, 2, 0, 0, 9, 0, 7],
[6, 4, 0, 3, 0, 0, 0, 0, 0],
]

if solve(grid,0,0):
    for i in range(9):
        for j in range(9):
            print(grid[i][j],end=" ")
        print()
else:
    print("No Solution Found!!")