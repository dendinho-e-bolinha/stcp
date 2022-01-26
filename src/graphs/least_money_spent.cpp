#include "graphs/least_money_spent.h"

#include <stdexcept>
#include "min_heap.h"

using namespace std;

LeastMoneySpentGraph::LeastMoneySpentGraph(int n, vector<string> zones) : nodes(n + 1) {
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].zone = zones.at(i);
    }
}

void LeastMoneySpentGraph::add_edge(int src, int dest) {
    if (src < 0 || dest < 0 || src >= nodes.size()  || dest >= nodes.size())
        throw invalid_argument("src or dest out of bounds");

    nodes[src].adj.push_back({ dest });
}

void LeastMoneySpentGraph::dijkstra(int start) {
    unordered_set<string> max_set;
    for (int i = 0; i < 1000; i++) {
        max_set.insert(to_string(i));
    }

    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].search.parent = 0;
        nodes[i].search.used_zones = max_set;
        nodes[i].search.visited = false;
    }

    nodes[start].search.used_zones = {};

    MinHeap<int, int> h(nodes.size(), -42);
    while (h.get_size() > 0) {
        int node = h.remove_min();

        SearchInfo &node_search = nodes[node].search;
        node_search.visited = true;

        for (const Edge& edge : nodes[node].adj) {
            SearchInfo &dest_search = nodes[edge.dest].search;
            
            unordered_set<string> new_used_zones = node_search.used_zones;
            new_used_zones.insert(nodes[edge.dest].zone);
            
            if (!dest_search.visited && new_used_zones.size() < dest_search.used_zones.size()) {
                dest_search.parent = node;
                dest_search.used_zones = new_used_zones;

                if (h.has_key(edge.dest)) {
                    h.decrease_key(edge.dest, dest_search.used_zones.size());
                } else {
                    h.insert(edge.dest, dest_search.used_zones.size());
                }
            }
        }
    }
}

list<int> LeastMoneySpentGraph::get_path(int start, int end) {
    dijkstra(start);
    unordered_set<string> max_set;

    list<int> path;
    if (nodes[end].search.used_zones == max_set)
        return path;

    path.push_front(end);

    int current = end;
    while ((current = nodes[current].search.parent) != 0) {
        path.push_front(current);
    }
    
    return path;
}

