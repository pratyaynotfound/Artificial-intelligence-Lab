#include<MandCP.h>

//check if the state is safe or not
bool is_Safe(State &a){
    if(a.numMissLeft<a.numCanbLeft && a.numMissRignt<a.numCanbRight)
        return true;
}

//is goal state or not
bool is_goal(State &g){
    if(g.numMissLeft == 0 && g.numCanbLeft == 0 && g.boatAtLeft == false)
        return true;
}

//for printing the state
void print_state(State &p){
    std::cout<<"No of Missionaries at left: "<<p.numMissLeft<<std::endl;
    std::cout<<"No of Cannibals at left: "<<p.numCanbLeft<<std::endl;
    std::cout<<"No of Missionaries at Right: "<<p.numMissRignt<<std::endl;
    std::cout<<"No of Cannibals at Right: "<<p.numCanbRight<<std::endl;
    if(p.boatAtLeft)
        std::cout<<"Boat at Left."<<std::endl;
    else
        std::cout<<"Boat at Right."<<std::endl;
}

//get the total no of moves
int get_total_moves(){
    return tmoves;
}

//for determining the valid moves
std::vector<std::pair<int,int>> valid_moves(State& current_state){

}

//get the next state
std::set<State> nextState(State &p){

}