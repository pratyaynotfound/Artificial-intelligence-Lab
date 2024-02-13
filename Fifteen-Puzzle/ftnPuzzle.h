// ftnPuzzle.h

#ifndef FTNPUZZLE_H
#define FTNPUZZLE_H

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

typedef std::pair<int, int> Pair;

class State{
    public:
    std::vector<int> Matrix;
    int g,h,f;
    friend std::ostream& operator<<(std::ostream&, const State&);

    State(){};
    State(std::vector<int> matr):Matrix(matr){
        g = 0;
        f = 0;
        h = 0;
    };
    void generate_children(std::vector<State>&);
    Pair find_empty();
    bool is_goal();
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