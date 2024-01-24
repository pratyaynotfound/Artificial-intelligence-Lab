#include<iostream>
#include<vector>
#include<cassert>

class State{
    private:
    unsigned int miss;
    unsigned int canb;
    bool boatAtLeft;

    public:
    State(unsigned int,unsigned int,bool);

    bool is_Safe();
    bool is_goal() const;
    void printState();
    int get_total_moves();
    std::vector<State> nextState();
    bool solve();

};

