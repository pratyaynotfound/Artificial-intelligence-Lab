#include "ftnPuzzle.h"

int rMax, cMax;
State goal, init;
int row[] = {1, 0, -1, 0};
int col[] = {0, 1, 0, -1};

// bool State::operator==(const State &other) const {
//     return (Matrix == other.Matrix);
// }

ostream &operator<<(ostream &os, const State &a) {
    for (int i = 0; i < rMax; ++i) {
        for (int j = 0; j < cMax; ++j) {
            os << a.Matrix[i * cMax + j] << " ";
        }
        os << "\n";
    }
    return os;
}

bool State::operator<(const State &other) const {
    return f > other.f;
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
                return make_pair(i, j);
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

void State::generate_children(std::vector<State> &successors) {
    Pair empty_pos = find_empty();
    for (int i = 0; i < 4; i++) {
        int newRow = empty_pos.first + row[i];
        int newCol = empty_pos.second + col[i];

        if (is_safe(newRow, newCol)) {
            State successorState = *this;
            swap(successorState.Matrix[empty_pos.first * cMax + empty_pos.second],
                 successorState.Matrix[newRow * cMax + newCol]);

            successors.push_back(successorState);
        }
    }
}
template <typename T>
void printPriorityQueue(const std::priority_queue<T>& pq) {
    std::priority_queue<T> copy = pq;  // Create a copy of the original priority queue

    // Print elements from the copy
    while (!copy.empty()) {
        std::cout << copy.top()<<"Huristics: "<<copy.top().f <<"\n\n";
        copy.pop();
    }
}

void solveAstar(State &initial, State &goal_s, int maxR, int maxC) {
    init = initial;
    goal = goal_s;

    rMax = maxR;
    cMax = maxC;

    priority_queue<State> pq; 
    std::vector<State> visited;
    pq.push(init);
    visited.push_back(init);
    int count_iters = 0;

    std::cout << "Initial ###\n" << initial << std::endl;

    while (!pq.empty()) {
        count_iters++;
        // std::sort(pq.begin(),pq.end());
        State current_state = pq.top();
        printPriorityQueue(pq);
        std::cout<<"Hval: "<< current_state.h<<"\n";
        pq.pop();

        if (current_state.is_goal()) {
            std::cout << "Goal found!\n" << current_state << std::endl;
            std::cout << "Total no of Iterations: " << count_iters << std::endl;
            break;
        }


        std::vector<State> successors;
        current_state.generate_children(successors);
        visited.push_back(current_state);

        for (auto successor : successors) {
            if (!find(visited,successor)) {
                // std::cout<<"Here!";
                successor.g = current_state.g + 1;
                successor.h = huristic(successor);
                successor.f = successor.g + successor.h;

                pq.push(successor);
            }
        }
        std::cout << "\n=========================================\n";
    }
}
