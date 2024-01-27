#ifndef MANDCP_H
#define MANDCP_H

#include<iostream>
#include<vector>
#include<set>
#include<queue>

typedef std::pair<int, int> Move;

struct State {
    int numMissLeft;
    int numCanbLeft;
    int numMissRignt;
    int numCanbRight;
    bool boatAtLeft;

    bool operator==(const State& other) const {
        return (
            numMissLeft == other.numMissLeft &&
            numMissRignt == other.numMissRignt &&
            numCanbLeft == other.numCanbLeft &&
            numCanbRight == other.numCanbRight &&
            boatAtLeft == other.boatAtLeft);
    }

    bool operator<(const State& other) const {
        if (numMissLeft != other.numMissLeft)
            return numMissLeft < other.numMissLeft;
        if (numMissRignt != other.numMissRignt)
            return numMissRignt < other.numMissRignt;
        if (numCanbLeft != other.numCanbLeft)
            return numCanbLeft < other.numCanbLeft;
        if (numCanbRight != other.numCanbRight)
            return numCanbRight < other.numCanbRight;
        return boatAtLeft < other.boatAtLeft;
    }

    friend std::ostream& operator<<(std::ostream& os, const State& state) {
        os << "(" << state.numMissLeft << ", " << state.numCanbLeft << ", " << (state.boatAtLeft?"1":"0") << ") ("
           << state.numMissRignt << ", " << state.numCanbRight << ", " << ((!state.boatAtLeft)?"1":"0") << ")";
        return os;
    }
};

// External declaration of global variables and functions
extern std::vector<Move> moves;
extern State goal_state;
extern unsigned int tmoves;

// Function declarations
void initialize_moves();
bool is_safe(const State&);
bool is_goal(const State&);
unsigned int get_total_moves();

std::vector<Move> valid_moves(const State&);
State move_state(const State&, const Move&);
std::vector<State> get_next_state(const State&);
bool solve(const State&, const State&);

#endif // MANDCP_H
