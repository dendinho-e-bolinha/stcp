#pragma once

#include <vector>
#include <list>
#include <string>
#include <iostream>

class LeastStopsGraph {

   struct SearchInfo {
        int parent;
        int distance;

        bool visited;
    };

    struct Edge {
        int dest;
    };

    struct Node {
        std::list<Edge> adj;
        SearchInfo search;
    };

    int n;
    std::vector<Node> nodes;

    void bfs(int s);

public:
    LeastStopsGraph(int n);
    
    void add_edge(int src, int dest);
};


