#include"MandCP.h"

int main(){
    State initialState = {3, 3, 0, 0, true};
    State goalState = {0, 0, 3, 3, false};

    std::cout<<"Initial State"<<std::endl;
    print_state(initialState);

    if(solve(initialState,goalState)){
        std::cout<<"Solution found!"<<"\nTotal moves: "<<get_total_moves()<<std::endl;
    }
    else{
        std::cout<<"No solution found!"<<std::endl;
    }
}