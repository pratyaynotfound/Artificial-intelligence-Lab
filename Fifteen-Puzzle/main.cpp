#include "ftnPuzzle.h"

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> inpur_arr;
    
    for(int i = 0;i<n*n;i++){
        int num;
        std::cin>>num;
        inpur_arr.push_back(num);
    }
    State initial(inpur_arr);
    
    std::vector<int> goal_vec;

    if( n == 4)
        goal_vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    else
        goal_vec = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    State goal(goal_vec);

    clock_t t;
    t = clock();
    solveAstar(initial, goal,n,n);
    t = clock()-t;
    std::cout<< "\nTime: " <<((double)t) / CLOCKS_PER_SEC <<" secs."<<std::endl;
    return 0;
}