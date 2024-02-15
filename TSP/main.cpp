#include "TSP.h"


int main(){
    int v;
    Graph G(v);
    std::vector<Edge> mstE;
    int mstW = 0;

    inputGraph(G,v);
    boost::kruskal_minimum_spanning_tree(G,std::back_inserter(mstE));
    for(auto it: mstE){
        mstW += get(boost::edge_weight,G,it);
    }

    std::vector<int> root = {mstW,0,mstW,0,0,1,0};
    if(!AstarTSP(G,root,v)){
        std::cout<<"Solution not found!!"<<std::endl;
    }
    return 0;
}
