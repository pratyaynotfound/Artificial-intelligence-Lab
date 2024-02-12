// ftnPuzzle.h

#ifndef FTNPUZZLE_H
#define FTNPUZZLE_H

#include <iostream>
#include <vector>
#include <queue>

typedef std::pair<int, int> Pair;

class State{
    public:
    std::vector<int> Matrix;
    int g,h,f;
    State* parent;
    friend std::ostream& operator<<(std::ostream&, const State&);

    State(){};
    State(std::vector<int> matr,int g, int h, int f):Matrix(matr),g(g),h(h),f(f){
        parent = nullptr;
    };
    void generate_children(std::vector<State>&);
    Pair find_empty();
    bool is_goal();
    // bool operator==(const State&) const;
    bool operator<(const State&) const;
};



extern int row[];
extern int col[];
extern int rMax, cMax;
extern State goal;

bool is_safe(int, int);
bool find(std::vector<State> &,State&);
int huristic(State&);
Pair findInGoal(int);
void solveAstar(State &,State &,int,int);

#endif