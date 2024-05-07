
from csp import *

def sudoku_solver():
	mygame = Sudoku(easy1)
    # an instance of sudoku
	mygame.display(mygame.infer_assignment())

    #Arc consistency algorithm
	AC3(mygame)
    # infer the assignment from the arc consistent domain
    # display the game
	print("******** AFTER ARC CONSISTENCY **************")
	mygame.display(mygame.infer_assignment())
	
	
sudoku_solver()

