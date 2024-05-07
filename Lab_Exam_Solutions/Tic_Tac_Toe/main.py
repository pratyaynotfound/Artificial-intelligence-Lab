from games import *


def main():
    print("hello! Ready to play tic-tac-toe against a computer?")
    mygame = TicTacToe()

    #mygame.play_game(minmax_player,random_player)
    mygame.play_game(minmax_player, query_player)

main()
