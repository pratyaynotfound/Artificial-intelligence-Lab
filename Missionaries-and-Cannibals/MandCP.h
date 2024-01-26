#ifndef MANDCP_H
#define MANDCP_H

#include<iostream>
#include<vector>
#include<set>
#include<queue>

typedef std::pair<int, int> Move;

struct State {
    unsigned int numMissLeft;
    unsigned int numCanbLeft;
    unsigned int numMissRignt;
    unsigned int numCanbRight;
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
        // You can choose any criteria for ordering State objects here
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
};

// External declaration of global variables and functions
extern std::vector<Move> moves;
extern State goal_state;
extern unsigned int tmoves;

// Function declarations
void initialize_moves();
bool is_safe(const State&);
bool is_goal(const State&);
void print_state(const State&);
unsigned int get_total_moves();

std::vector<Move> valid_moves(const State&);
State move_state(const State&, const Move&);
std::vector<State> get_next_state(const State&);
bool solve(const State&, const State&);

#endif // MANDCP_H
