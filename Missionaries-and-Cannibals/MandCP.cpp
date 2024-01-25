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
Moves valid_moves(State& current_state){
    Moves valid_move;
    State temp;
    for(auto move: moves){
        if(current_state.boatAtLeft){
            temp.numCanbLeft = current_state.numCanbLeft - move.first;
            temp.numMissLeft = current_state.numMissLeft - move.second;

            temp.numCanbRight = current_state.numCanbRight + move.first;
            temp.numMissRignt = current_state.numMissRignt + move.second;

            if(is_Safe(temp)){
                valid_move.push_back(move);
            }
        }
        else{
            temp.numCanbLeft = current_state.numCanbLeft + move.first;
            temp.numMissLeft = current_state.numMissLeft + move.second;

            temp.numCanbRight = current_state.numCanbRight - move.first;
            temp.numMissRignt = current_state.numMissRignt - move.second;

            if(is_Safe(temp)){
                valid_move.push_back(move);
            }
        }
        
    }
}

//get a move by one state and a valid move 
State move_state(State& current,Move& this_move){
    State temp_move;

    if(current.boatAtLeft){
        temp_move.numCanbLeft = current.numCanbLeft - this_move.first;
        temp_move.numMissLeft = current.numMissLeft - this_move.second;

        temp_move.numCanbRight = current.numCanbRight + this_move.first;
        temp_move.numMissRignt = current.numMissRignt + this_move.second;
    }
    else{
        temp_move.numCanbLeft = current.numCanbLeft + this_move.first;
        temp_move.numMissLeft = current.numMissLeft + this_move.second;

        temp_move.numCanbRight = current.numCanbRight - this_move.first;
        temp_move.numMissRignt = current.numMissRignt - this_move.second;
    }

    return temp_move;
}

//get the next state
std::vector<State> get_next_state(State &p){
    Moves valid = valid_moves(p);
    std::vector<State> set_of_states;
    for(auto move: valid){
        State new_state = move_state(p,move);

        set_of_states.push_back(new_state);
    }

    return set_of_states;
}

//solve
bool solve(State& init, State& goal){
    
}