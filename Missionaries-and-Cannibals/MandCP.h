#ifndef MANDCP_H
#define MANDCP_H

#include<iostream>
#include<vector>
#include<cassert>
#include<set>
typedef std::vector<std::pair<int, int>> Moves;
Moves moves = {{0, 1}, {0, 2}, {1, 1}, {1, 0}, {2, 0}};

struct State{
    unsigned int numMissLeft,numMissRignt;
    unsigned int numCanbLeft,numCanbRight;
    bool boatAtLeft;

    bool operator==(const State& other) const {
    return 
        numMissLeft == other.numMissLeft &&
        numMissRignt == other.numMissRignt &&
        numCanbLeft == other.numCanbLeft &&
        numCanbRight == other.numCanbRight &&
        boatAtLeft == other.boatAtLeft;
    }
};

unsigned int tmoves = 0;

bool is_Safe(State&);
bool is_goal(State&, State&);
void print_state(State&);
int get_total_moves();

std::vector<std::pair<int,int>> valid_moves(State&);
std::set<State> get_next_state(State&);
bool solve(State&, State&);



#endif MANDCP_H