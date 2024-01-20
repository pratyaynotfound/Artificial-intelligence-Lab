#include<iostream>
#include<algorithm>  // for std::fill
#define N 4
int count = 0;

bool isSafe(int (&board)[N], int row, int col);
bool solveNQ(int (&board)[N], int row);
void solve();
void printSol(int board[N]);

int main() {
    clock_t t;
    t = clock();
    solve();    //get all possible solutions measure the time alongside
    t = clock()-t;

    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    std::cout<<"================================="<<std::endl;
    std::cout<<N<<"-Queen Solutions:"<<std::endl;
    std::cout<<"Total no of solutions: "<<count<<std::endl;
    std::cout<<"Total time taken: "<<time_taken<<" Sec"<<std::endl;
    std::cout<<"================================="<<std::endl;

    return 0;
}

void solve() {
    int board[N];
    std::fill(board, board + N, -1);
    if (!solveNQ(board, 0)) {
        std::cout << "Solution not found!" << std::endl;
    }
}

bool isSafe(int (&board)[N], int row, int col) {
    // Check the same row
    for (int i = 0; i < row; i++) {
        if (board[i] == col)
            return false;
    }

    // Check for the left diagonals
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i] == j)
            return false;
    }

    // Check for the right diagonals
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i] == j)
            return false;
    }

    return true;
}

bool solveNQ(int (&board)[N], int row) {
    if (row == N) {
        printSol(board);
        count++;
        return true;
    }
    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;

            res = solveNQ(board, row + 1) || res;

            board[row] = -1;
        }
    }
    return res;
}

void printSol(int board[N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                std::cout << "Q ";
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
