#ifndef TSP_H
#define TSP_H


#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/graph_utility.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, 
    boost::no_property, boost::property<boost::edge_weight_t, int>> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef boost::graph_traits<Graph>::edge_descriptor Edge;
typedef std::pair<int, int> EdgePair;
typedef boost::property_map<Graph, boost::edge_weight_t>::type EWM;

struct PathState{
    std::vector<int> visited;
    int cost;
    int estimate;
    bool operator<(const PathState&) const;
}

std::ostream& operator<<(std::ostream &,std::vector<int>);


void inputGraph(Graph&,int &);
int heuMST(const std::vector<int>, Graph&);
void generate_successors(std::vector<int>&,std::set<std::vector<int>>&,Graph&);
bool AstarTSP(Graph& G,std::vector<int>&,int);




#endif
