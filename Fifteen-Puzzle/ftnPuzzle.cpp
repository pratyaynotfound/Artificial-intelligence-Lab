#include "ftnPuzzle.h"

int rMax, cMax;
State goal, init;
int row[] = {1, 0, -1, 0};
int col[] = {0, 1, 0, -1};

std::ostream &operator<<(std::ostream &os, const State &a) {
    for (int i = 0; i < rMax; ++i) {
        for(int j = 0;j < cMax;j++){
            os << a.Matrix[i*cMax+j]<<"\t";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    return os;
}

bool State::operator<(const State &other) const {
    return f >= other.f;
}

bool State::is_goal() {
    return this->Matrix == goal.Matrix;
}

bool is_safe(int row, int col) {
    return (row >= 0 && col >= 0 && row < rMax && col < cMax);
}

Pair State::find_empty() {
    for (int i = 0; i < rMax; ++i) {
        for (int j = 0; j < cMax; ++j) {
            if (Matrix[i * cMax + j] == 0) {
                return std::make_pair(i, j);
            }
        }
    }
    return {-1, -1};
}

Pair findInGoal(int key) {
    for (int i = 0; i < rMax; i++) {
        for (int j = 0; j < cMax; j++) {
            if (key == goal.Matrix[i*cMax+j])
                return {i, j};
        }
    }
    return {-1, -1};
}

//returns true if the element is found in the vector of states, false otherwise
bool find(std::vector<State> &vect,State& suc){
    for(auto it = vect.begin();it!=vect.end();it++){
        if((*it).Matrix == suc.Matrix){
            return true;
        }
    }
    return false;
}

int huristic(State &this_state) {
    int mhtnDist = 0;
    for (int i = 0; i < rMax; i++) {
        for (int j = 0; j < cMax; j++) {
            Pair posInGoal = findInGoal(this_state.Matrix[i * cMax + j]);
            if (posInGoal.first == -1 || posInGoal.second == -1) {
                std::cout << "Position in goal not found!\nAborting Process...\n";
                exit(0);
            }
            mhtnDist = mhtnDist + abs(i-posInGoal.first) + abs(j-posInGoal.second);
        }
    }
    return mhtnDist;
}

void State::generate_children(std::vector<State>& children) {
    Pair emptyPos = find_empty();
    for (int i = 0; i < 4; i++) {
        int newX = emptyPos.first + row[i];
        int newY = emptyPos.second + col[i];

        if (is_safe(newX, newY)) {
            State child(*this);
            std::swap(child.Matrix[emptyPos.first * cMax + emptyPos.second],
                 child.Matrix[newX * cMax + newY]);
            child.g++;
            child.h = huristic(child);
            child.f = child.g + child.h;

            children.push_back(child);
        }
    }
}
template <typename T>
void printPriorityQueue(const std::priority_queue<T>& pq) {
    std::priority_queue<T> copy = pq;
    // Print elements from the copy
    std::cout << copy.top()<<"Huristics: "<<copy.top().f <<"\n\n";
    copy.pop();
    
}

void solveAstar(State &initial, State &goal_s, int maxR, int maxC) {
    init = initial;
    goal = goal_s;

    rMax = maxR;
    cMax = maxC;

    std::priority_queue<State> pq; 
    std::vector<State> visited;
    pq.push(init);
    int count_iters = 0;

    std::cout << "Initial ###\n" << initial << std::endl;

    std::vector<State> successors;
    initial.generate_children(successors);

    while (!pq.empty()) {
        count_iters++;
        State current_state = pq.top();
        std::cout<<current_state;
        pq.pop();

        if (current_state.is_goal()) {
            std::cout << "Goal found!\n" << current_state << std::endl;
            std::cout << "Total no of Iterations: " << count_iters << std::endl;
            std::cout << "Height: "<< current_state.g<<"\nPath:\n";
            break;
        }
    
        std::vector<State> successors;
        current_state.generate_children(successors);
        visited.push_back(current_state);

        for (State& child : successors) {
            if (!find(visited,child)) {
                pq.push(child);
            }
        }
    }
}