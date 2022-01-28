#pragma once

#include <vector>
#include <list>
#include <string>
#include <optional>
#include <deque>

class LeastBusChangesGraph {

    struct SearchInfo {
        int parent;

        std::pair<int, int> distance; // [line_changes, bus_stops]
        bool visited;
    };

    struct Edge {
        int dest;
        int weight;
    };


    struct Node {
        std::deque<Edge> adj;
        SearchInfo search;
    };

    std::vector<Node> nodes;

    void dijkstra(int start);

public:
    LeastBusChangesGraph(int n);
    
    void resize(int n, bool force);
    void add_edge(int src, int dest, int weight);
    std::list<int> get_path(int start, int end);
};
