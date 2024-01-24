#include<MandCP.h>

//constructor
State::State(unsigned int numMiss, unsigned int numCann, bool boatAtlefT):
    miss(numMiss), canb(numCann), boatAtLeft(boatAtlefT){};

//check if the state is safe or not
bool State::is_Safe(){
    if(miss>canb)
        return true;
}

//is goal state or not
bool State::is_goal() const{

}