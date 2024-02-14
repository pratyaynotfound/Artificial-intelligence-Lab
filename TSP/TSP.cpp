#include "TSP.h"


void inputGraph(Graph& G,int &v){
    std::cout<<"Enter the number of vertices and edges:"<<std::endl;
    std::cin>>v;

    std::cout<<"Enter the Adjacency list(use blank space as delimeter):"<<std::endl;

    int e;
    for(int i = 0;i<v;i++){
        for(int j = 0;j<v;j++){
            std::cin>>e;
            boost::add_edge(i,j,-e,G);
        }
    }
}

int heuMST(const std::vector<int> node, Graph& G){
    int num_v = boost::num_vertices(G), p = node.size()-6, l = 1000;
    Graph H(num_v);

    EWM weight_map = boost::get(boost::edge_weight, G);

    for(int i = 0;i <num_v ;i++){
        for(int j = 0;j<num_v;j++){
            boost::add_edge(i,j,weight_map[boost::edge(i,j,G).first],H);
        }
    }
    if(node.size() == 8){
        auto e = boost::edge(node[6],node[7],H);
        boost::put(boost::edge_weight,H,e.first,l);
        auto e_ = boost::edge(node[7],node[6],H);
        boost::put(boost::edge_weight,H,e_.first,l);
    }
    else{
        for (int i = 7; i < node.size()-1; i++){
            for (int j = 0; j<num_v; j++){
                if(j!=node[i]){
                    auto e = boost::edge(node[i], j, H);    
                    boost::put(boost::edge_weight, H, e.first, l);
                    auto e_ = boost::edge(j, node[i], H);    
                    boost::put(boost::edge_weight, H, e_.first, l);
                }
            }
        }
    }

    std::vector<Edge> E;
    int W = 0;
    boost::kruskal_minimum_spanning_tree(H,std::back_inserter(E));
    for(auto e: E){
        W += get(boost::edge_weight,H,e);
    }
    return W;
}   

void generate_successors(std::vector<int>& node,std::set<std::vector<int>>& succ,Graph& g){
    bool present;

    int uid = node[3];
    int n = boost::num_vertices(g);

    for(int v = 0;v<n;v++){
        for(int i = 6;i<node.size();i++){
            if(v == node[i])
                present = true;
        }
        if(!present){
            std::vector<int> new_n(node.size()+1);

            boost::property_map<Graph,boost::edge_weight_t>::type weightMap = boost::get(boost::edge_weight,g);
            boost::graph_traits<Graph>::edge_descriptor e = edge(node[node.size()-1],v,g).first;

            int weightEdge = boost::get(weightMap,e);

            new_n = {weightEdge+node[1],heuMST(new_n,g),new_n[1]+new_n[2],++uid,new_n[3],new_n[5]+1};

            for(int i=6;i<new_n.size();i++){
                new_n[i] = node[i];
            }

            new_n[node.size()] = v;
            succ.insert(node);
        }
    }
}

std::ostream& operator<<(std::ostream &os,std::vector<int> node){
    for(int i = 6;i<node.size();i++){
        os<<node[i]+1<<"\t";
    }
}

bool AstarTSP(Graph& G,std::vector<int>& root,int v){
    std::priority_queue<std::vector<int>> frontier;
    std::set<std::vector<int>> visited;

    frontier.push(root);
    while(!frontier.empty()){
        std::vector<int> N = frontier.top();
        frontier.pop();

        if(N.size() == v+6){
            visited.insert(N);
            std::cout<<"Solution found!"<<std::endl;
            std::cout<<N<<std::endl;
            return true;
        }
        else{
            visited.insert(N);
            std::set<std::vector<int>> succssors;
            generate_successors(N,succssors,G);
            for(auto it: succssors){
                if(visited.find(it) == visited.end())
                    frontier.push(it);
            }
        }
    }
    return false;
}


