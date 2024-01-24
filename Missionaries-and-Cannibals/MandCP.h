#ifndef MANDCP_H
#define MANDCP_H

#include<iostream>
#include<vector>
#include<cassert>
#include<set>

struct State{
    unsigned int numMiss;
    unsigned int numCanb;
    bool boatAtLeft;
};

unsigned int tmoves = 0;

bool is_Safe(State);
bool is_goal(State);
void print_state(State);
int get_total_moves();
std::set<State> nextState(State);
bool solve();

#endif MANDCP_H