#include<MandCP.h>

#define numM 3
#define numC 3

int main(){
    State initialState = {3, 3, 0, 0, true};
    State goalState = {0, 0, 3, 3, false};

    if(solve(initialState,goalState)){
        std::cout<<"Solution found!"<<"Total moves: "<<get_total_moves()<<std::endl;
    }
    else{
        std::cout<<"No solution found!"<<std::endl;
    }
}