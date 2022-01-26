#pragma once

#include <vector>
#include <list>
#include <string>
#include <iostream>

class LeastStopsGraph {

   struct SearchInfo {
        int parent;
        int num_stops;

        bool visited;
    };

    struct Edge {
        int dest;
    };

    struct Node {
        std::list<Edge> adj;
        SearchInfo search;
    };

    std::vector<Node> nodes;

    void bfs(int start);

public:
    LeastStopsGraph(int n);
    
    void add_edge(int src, int dest);
    std::list<int> get_path(int start, int end);
};


