#pragma once

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <unordered_set>

class LeastMoneySpentGraph {

   struct SearchInfo {
        int parent;
        std::unordered_set<std::string> used_zones;

        bool visited;
    };

    struct Edge {
        int dest;
    };

    struct Node {
        std::list<Edge> adj;

        std::string zone;
        SearchInfo search;
    };

    std::vector<Node> nodes;

    void dijkstra(int start);
    
public:
    LeastMoneySpentGraph(int n, std::vector<std::string> zones);
    
    void add_edge(int src, int dest);
    
    std::list<int> get_path(int start, int dest);
};


