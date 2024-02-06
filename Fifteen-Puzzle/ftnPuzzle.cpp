#include "ftnPuzzle.h"

int rMax,cMax;
State goal,init;
int row[] = {1,0,-1,0};
int col[] = {0,1,0,-1};

bool State::operator==(const State& other) const {
    return (Matrix == other.Matrix);
}


ostream& operator<<(ostream& os, const State& a) {
    for (auto i : a.Matrix) {
        for (auto j : i) {
            os << j << " ";
        }
        os << "\n";
    }
    return os;
}
bool State::operator<(const State& other) const {
    return f>other.f;
}

bool State::is_goal(){
    return this->Matrix == goal.Matrix;
}

bool is_safe(int row, int col) {
    return (row >= 0 && col >= 0 && row < rMax && col < cMax);
}

Pair State::find_empty() {
    for (int i = 0; i < (*this).Matrix.size(); ++i) {
        for (int j = 0; j < (*this).Matrix[i].size(); ++j) {
            if ((*this).Matrix[i][j] == 0) {
                return make_pair(i, j);
            }
        }
    }
    return {-1, -1};
}

Pair findInGoal(int key) {
    for (int i = 0; i < rMax; i++) {
        for (int j = 0; j < cMax; j++) {
            if (key == goal.Matrix[i][j])
                return {i, j};
        }
    }
    return {-1, -1};
}

int huristic(State& this_state) {
    int mhtnDist = 0;
    for (int i = 0; i < rMax; i++) {
        for (int j = 0; j < cMax; j++) {
            Pair posInGoal = findInGoal(this_state.Matrix[i][j]);
            if (posInGoal.first == -1 || posInGoal.second == -1) {
                std::cout << "Position in goal not found!\nAborting Process...\n";
                exit(0);
            }
            mhtnDist = mhtnDist + (abs(i - posInGoal.first) + abs(j - posInGoal.second));
        }
    }
    return mhtnDist;
}

void State::generate_children(vector<State>& successors){

    for (int i = 0; i < 4; i++) {
        Pair empty_pos = (*this).find_empty();
        int newRow = empty_pos.first + row[i];
        int newCol = empty_pos.second + col[i];

        if (is_safe(newRow, newCol)) {
            State successorState = *this;

            swap(successorState.Matrix[empty_pos.first][empty_pos.second],
                 successorState.Matrix[newRow][newCol]);

            successors.push_back(successorState);
        }
    }
}

// Implement the remaining functions as needed...

void solveAstar(State& initial,State& goal_s,int maxR,int maxC){
    init = initial;
    goal = goal_s;

    rMax = maxR;
    cMax = maxC;

    //debug
    // std::cout<<initial<<std::endl;
    // for(auto child: initial.generate_children())
    //     std::cout<<child<<std::endl;

    priority_queue<State> pq;
    std::set<State> visited;
    pq.push(init);
    visited.insert(init);
    int count_iters = 0;

    while(!pq.empty()){
        count_iters++;
        State current_state = pq.top();
        pq.pop();

        if(current_state.is_goal()){
            std::cout<<"Goal found!\n"<<current_state<<std::endl;
            std::cout<<"Total no of Iterations: "<<count_iters<<std::endl;
            break;
        }

        std::vector<State> succssors;
        current_state.generate_children(succssors);
        for(auto& successor: succssors){
            if(visited.find(successor) != visited.end()){
                successor.g = current_state.g + 1;
                successor.h = huristic(successor);
                successor.f = successor.g + successor.h;
                // successor.parent = &current_state;

                pq.push(successor);
                visited.insert(successor);
            }
        }
    }
}