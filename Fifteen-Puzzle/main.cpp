#include "ftnPuzzle.h"
#define MAX_ROW 4
#define MAX_COL 4
// {1, 2, 3},
// {5, 6, 0},
// {7, 8, 4}

int main()
{
//     State initial{{
//     {8,  4,  2},
//     {1,  0,  6},
//     {7,  5,  3}
// }, 0, 0, 0}; 

//     State goal{{
//         {1,2,3},
//         {4,5,6},
//         {7,8,0}
//     },0,0,0};

State initial{{
    {5, 1, 6, 4},
    {2, 9, 7, 8},
    {13, 3, 10, 12},
    {14, 0, 15, 11}
}, 0, 0, 0}; 

State goal{{
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 0}
}, 0, 0, 0};


    //  Debug
    // std::cout<<initial_state<<std::endl;
    // State new_state = move_state(initial_state,{-1,0});
    // std::cout<<new_state<<std::endl;
    clock_t t;
    t = clock();
    solveAstar(initial, goal,MAX_ROW,MAX_COL);
    t = clock()-t;
    std::cout<< "\nTime: " <<((double)t) / CLOCKS_PER_SEC <<" secs."<<std::endl;
    return 0;
}