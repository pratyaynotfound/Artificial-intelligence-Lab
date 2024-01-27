#include"MandCP.h"
#define numCanb 3
#define numMiss 3

int main(){
    State initialState = {numCanb, numMiss, 0, 0, true};
    State goalState = {0, 0, numCanb, numMiss, false};

    std::cout<<"Initial State: \n"<<initialState << " Level: 0"<<std::endl;
    solve(initialState,goalState);
}