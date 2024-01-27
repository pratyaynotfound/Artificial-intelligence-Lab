#include"MandCP.h"
#define numCanb 3
#define numMiss 3

int main(){
    State initialState = {numMiss, numCanb, 0, 0, true};
    State goalState = {0, 0, numMiss, numCanb, false};

    // std::cout<<goalState;
    std::cout<<"Initial State: \n"<<initialState << " Level: 0"<<std::endl;
    solve(initialState,goalState);
}