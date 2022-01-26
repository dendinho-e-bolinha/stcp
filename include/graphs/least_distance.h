#pragma once

#include <vector>
#include <list>
#include <string>

class LeastDistanceGraph {

   struct SearchInfo {
        int parent;
        double distance;

        bool visited;
    };

    struct Edge {
        int dest;

        double distance;
    };


    struct Node {
        std::list<Edge> adj;
        SearchInfo search;
    };

    std::vector<Node> nodes;

    void dijkstra(int start);
    
public:
    LeastDistanceGraph(int n);
    
    void add_edge(int src, int dest, double distance);
    std::list<int> get_path(int start, int end);
};
