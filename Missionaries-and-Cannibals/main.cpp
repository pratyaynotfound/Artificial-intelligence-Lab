#include<MandCP.h>

#define numM 3
#define numC 3

int main(){
    State atStart{numM,numC,true};
    if(solve()){
        std::cout<<"Solution found!"<<"Total moves: "<<get_total_moves()<<std::endl;
    }
    else{
        std::cout<<"No solution found!"<<std::endl;
    }
}