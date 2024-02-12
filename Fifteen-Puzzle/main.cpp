#include "ftnPuzzle.h"
#define MAX_ROW 4
#define MAX_COL 4
// {1, 2, 3},
// {5, 6, 0},
// {7, 8, 4}

int main()
{
//     State initial{{
//     {6, 4, 3, 2, 8, 7, 1, 5, 0}
// }, 0, 0, 0}; 

//     State goal{{
//     {1,2,3,4,5,6,7,8,0}
//     },0,0,0};

//1923512111013608714154


State initial{
    {1, 9, 2, 3, 5, 12, 11, 10, 13, 6, 0, 8, 7, 14, 15, 4}
, 0, 0, 0}; 


// State initial{
//     {1, 3, 4, 0, 5, 2, 7, 8, 9, 6, 10, 11, 13, 14, 15,12}
// , 0, 0, 0};

State goal{
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0}
, 0, 0, 0};


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