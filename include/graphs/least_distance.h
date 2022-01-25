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

    int n;
    std::vector<Node> nodes;

    void djikstra(int s);

public:
    LeastDistanceGraph(int n);
    
    void add_edge(int src, int dest, double distance);
};


