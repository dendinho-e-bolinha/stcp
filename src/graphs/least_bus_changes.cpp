#include "graphs/least_bus_changes.h"

#include <stdexcept>
#include <queue>
#include "min_heap.h"

using namespace std;

#define INF 1000000

LeastBusChangesGraph::LeastBusChangesGraph(int n) : n(n), nodes(n + 1) {}

void LeastBusChangesGraph::add_edge(int src, int dest, string line) {
    if (src < 1 || dest < 1 || src > n || dest > n)
        throw invalid_argument("src or dest out of bounds");

    nodes[src].adj.push_back({ dest, line });
}

void LeastBusChangesGraph::dijkstra(int start) {
    for (int i = 1; i <= n; i++) {
        Node &node = nodes.at(i);

        node.search.parent = 0;
        node.search.distance = { INF, INF };
        node.search.visited = false;
    }

    nodes[start].search.distance = { 0, 0 };

    MinHeap<int, pair<int, int>> h(n, -1);
    while (h.get_size() > 0) {
        int node = h.remove_min();

        SearchInfo &node_search = nodes[node].search;
        node_search.visited = true;

        for (const Edge& edge : nodes[node].adj) {
            SearchInfo &dest_search = nodes[edge.dest].search;
            
            pair<int, int> new_distance = node_search.distance;
            if (edge.line != node_search.line_taken) 
                new_distance.first += 1;

            new_distance.second += 1;

            if (!dest_search.visited && new_distance < dest_search.distance) {
                dest_search.parent = node;
                dest_search.distance = new_distance;
                dest_search.line_taken = edge.line;

                if (h.has_key(edge.dest)) {
                    h.decrease_key(edge.dest, dest_search.distance);
                } else {
                    h.insert(edge.dest, dest_search.distance);
                }
            }
        }
    }
}
