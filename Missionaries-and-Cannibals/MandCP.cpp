#include "MandCP.h"

// Global variables
unsigned int tmoves = 0;
State goal_state;
std::vector<Move> moves;

// Initialize valid moves
void initialize_moves() {
    moves.push_back(std::make_pair(0, 1));
    moves.push_back(std::make_pair(0, 2));
    moves.push_back(std::make_pair(1, 1));
    moves.push_back(std::make_pair(1, 0));
    moves.push_back(std::make_pair(2, 0));

    //for 4,4 and 5,5
    
    // moves.push_back(std::make_pair(0, 3));
    // moves.push_back(std::make_pair(3, 0));
    // moves.push_back(std::make_pair(1, 2));
    // moves.push_back(std::make_pair(2, 1));
}

// Check if the state is safe or not
bool is_safe(const State& a) {
    return !((a.numMissLeft!=0 && a.numMissLeft < a.numCanbLeft) ||
             (a.numMissRignt!=0 && a.numMissRignt < a.numCanbRight) ||
             a.numCanbLeft + a.numCanbRight > goal_state.numCanbRight + goal_state.numCanbLeft ||
             a.numMissLeft + a.numMissRignt > goal_state.numMissRignt + goal_state.numMissLeft);
}

// Check if the state is the goal state
bool is_goal(const State& g) {
    return g == goal_state;
}

// Print the state
void print_state(const State& p) {
    std::cout<<"========================"<<std::endl;
    std::cout << "No of Missionaries at left: " << p.numMissLeft << std::endl;
    std::cout << "No of Cannibals at left: " << p.numCanbLeft << std::endl;
    std::cout << "No of Missionaries at Right: " << p.numMissRignt << std::endl;
    std::cout << "No of Cannibals at Right: " << p.numCanbRight << std::endl;
    if(p.boatAtLeft)
        std::cout<<"Boat at Left."<<std::endl;
    else
        std::cout<<"Boat at Right."<<std::endl;
    
    std::cout<<"========================"<<std::endl;
}

// Get the total number of moves
unsigned int get_total_moves() {
    return tmoves;
}

// Determine valid moves for a given state
std::vector<Move> valid_moves(const State& current_state) {
    std::vector<Move> valid_move;
    State temp;
    for (const auto& move : moves) {
        if (current_state.boatAtLeft) {
            temp.numCanbLeft = current_state.numCanbLeft - move.first;
            temp.numMissLeft = current_state.numMissLeft - move.second;

            temp.numCanbRight = current_state.numCanbRight + move.first;
            temp.numMissRignt = current_state.numMissRignt + move.second;

            if (is_safe(temp)) {
                valid_move.push_back(move);
            }
        } else {
            temp.numCanbLeft = current_state.numCanbLeft + move.first;
            temp.numMissLeft = current_state.numMissLeft + move.second;

            temp.numCanbRight = current_state.numCanbRight - move.first;
            temp.numMissRignt = current_state.numMissRignt - move.second;

            if (is_safe(temp)) {
                valid_move.push_back(move);
            }
        }
    }
    return valid_move;
}

// Get a new state by applying a valid move to a given state
State move_state(const State& current, const Move& this_move) {
    State temp_move;
    if (current.boatAtLeft) {
        temp_move.numCanbLeft = current.numCanbLeft - this_move.first;
        temp_move.numMissLeft = current.numMissLeft - this_move.second;

        temp_move.numCanbRight = current.numCanbRight + this_move.first;
        temp_move.numMissRignt = current.numMissRignt + this_move.second;

        temp_move.boatAtLeft = !current.boatAtLeft;
    } else {
        temp_move.numCanbLeft = current.numCanbLeft + this_move.first;
        temp_move.numMissLeft = current.numMissLeft + this_move.second;

        temp_move.numCanbRight = current.numCanbRight - this_move.first;
        temp_move.numMissRignt = current.numMissRignt - this_move.second;

         temp_move.boatAtLeft = !current.boatAtLeft;
    }
    return temp_move;
}

// Get the next states reachable from a given state
std::vector<State> get_next_state(const State& p) {
    std::vector<Move> valid = valid_moves(p);
    std::vector<State> set_of_states;
    for (const auto& move : valid) {
        State new_state = move_state(p, move);
        set_of_states.push_back(new_state);
    }
    return set_of_states;
}

// Solve the problem starting from the initial state to reach the goal state
bool solve(const State& init, const State& goal) {
    initialize_moves();
    goal_state = goal;
    std::queue<State> q;
    std::set<State> explored;

    // print_state(init); //debug

    q.push(init);
    explored.insert(init);

    //debug

    // for(auto i: get_next_state(init)){
    //     // print_state(nextstate);
    //     std::cout<<"========================"<<std::endl;
    //     print_state(i);
    //     // std::cout<<"("<<i.first<<","<<i.second<<")"<<std::endl;
    // }

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (is_goal(current)) {
            print_state(current);
            std::cout << "Goal state found!" << std::endl;
            return true;
        }

        std::vector<State> next_states = get_next_state(current);
        for (const auto& next_state : next_states) {
            
            if (explored.find(next_state) == explored.end()) {
                q.push(next_state);
                explored.insert(next_state);
            }
        }
    }

    std::cout << "Goal state not reachable." << std::endl;
    return false;
}
