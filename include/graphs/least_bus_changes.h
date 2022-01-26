#pragma once

#include <vector>
#include <list>
#include <string>

class LeastBusChangesGraph {

    struct SearchInfo {
        int parent;
        std::string line_taken; // the line taken to get from the parent to this node

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

    std::vector<Node> nodes;

    void dijkstra(int start);

public:
    LeastBusChangesGraph(int n);
    
    void add_edge(int src, int dest, std::string line);
    std::list<std::pair<int, std::string>> get_path(int start, int end);
};

/*
    [ {34, "205"}, { 2100, "304" }, { 568, "304" }, { 786, "" } ]
*/
