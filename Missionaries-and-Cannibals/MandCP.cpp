#include<MandCP.h>

//check if the state is safe or not
bool is_Safe(State a){
    if(a.numMiss<a.numCanb)
        return true;
}

//is goal state or not
bool is_goal(State g){
    if(g.numMiss == 0 && g.numCanb == 0 && g.boatAtLeft == false)
        return true;
}

//for printing the state
void print_state(State p){
    std::cout<<"No of Missionaries at left: "<<p.numMiss<<std::endl;
    std::cout<<"No of Cannibals at left: "<<p.numCanb<<std::endl;
}

//get the total no of moves
int get_total_moves(){
    return tmoves;
}

//get the next state
std::set<State> nextState(State p){
    
}