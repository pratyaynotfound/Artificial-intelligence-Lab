// ftnPuzzle.h

#ifndef FTNPUZZLE_H
#define FTNPUZZLE_H

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef pair<int, int> Pair;

class State{
    public:
    std::vector<std::vector<int>> Matrix;
    int g,h,f;
    // State* parent;
    friend ostream& operator<<(ostream&, const State&);

    State(){};
    State(std::vector<std::vector<int>> matr,int g, int h, int f):Matrix(matr),g(g),h(h),f(f){};
    void generate_children(std::vector<State>&);
    Pair find_empty();
    bool is_goal();
    bool operator==(const State&) const;
    bool operator<(const State&) const;
};

extern int row[];
extern int col[];
extern int rMax, cMax;
extern State goal;

bool is_safe(int, int);
int huristic(State&);
Pair findInGoal(int);
void solveAstar(State &,State &,int,int);

#endif