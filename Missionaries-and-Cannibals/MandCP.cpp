#include<MandCP.h>

//check if the state is safe or not
bool is_Safe(State &a, State& goal){
    if((a.numMissLeft<a.numCanbLeft) || (a.numMissRignt<a.numCanbRight) || (a.numCanbLeft+a.numCanbRight>goal.numCanbRight+goal.numCanbLeft)|| (a.numMissLeft+a.numMissRignt>goal.numMissRignt+goal.numMissLeft))
        return false;
    return true;
}

//is goal state or not
bool is_goal(State &g, State &goal){
    if(g == goal)
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
    std::vector<std::pair<int,int>> valid_move;
    State temp;
    if(current_state.boatAtLeft){
        for(auto move: moves){
            temp.numCanbLeft = current_state.numCanbLeft - move.first;
            temp.numMissLeft = current_state.numMissLeft - move.second;

            temp.numCanbRight = current_state.numCanbRight + move.first;
            temp.numMissRignt = current_state.numMissRignt + move.second;

            if(is_Safe(temp)){
                valid_move.push_back(move);
            }
        }
    }
}

//get the next state
std::set<State> nextState(State &p){

}

//solve
bool solve(State& init, State& goal){

}