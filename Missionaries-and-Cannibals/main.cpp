#include"MandCP.h"

int main(){
    State initialState = {3, 3, 0, 0, true};
    State goalState = {0, 0, 3, 3, false};

    std::cout<<"Initial State: \n"<<initialState << " Level: 0"<<std::endl;
    solve(initialState,goalState);
}