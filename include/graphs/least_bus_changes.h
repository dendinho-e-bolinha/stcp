#pragma once

#include <vector>
#include <list>
#include <string>

#define INF 10000000

class LeastBusChangesGraph {

    struct SearchInfo {
        int parent;
        int line_taken; // index of the edge on the parent node - the line taken to get from the parent to this node

        std::pair<int, int> distance; // [line_changes, bus_stops]
        bool visited;
    };

    struct Edge {
        int dest;

        std::string line;
    };


    struct Node {
        std::vector<Edge> adj;
        SearchInfo search;
    };

    int n;
    std::vector<Node> nodes;

    void djikstra(int s);

public:
    LeastBusChangesGraph(int n);
    
    void add_edge(int src, int dest, std::string line);

    std::list<std::pair<int, std::string>> djikstra_path(int s, int e);
};

/*
    [ {34, "205"}, { 2100, "304" }, { 568, "304" }, { 786, "" } ]
*/

