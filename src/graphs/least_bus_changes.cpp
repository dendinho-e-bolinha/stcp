#include "graphs/least_bus_changes.h"

#include <stdexcept>

using namespace std;

LeastBusChangesGraph::LeastBusChangesGraph(int n) : n(n), nodes(n + 1) {}

void LeastBusChangesGraph::add_edge(int src, int dest, string line) {
    if (src < 1 || dest < 1 || src > n || dest > n)
        throw invalid_argument("src or dest out of bounds");

    nodes[src].adj.push_back({ dest, line });
}

void LeastBusChangesGraph::djikstra(int s) {
    // ...
}

list<pair<int, string>> LeastBusChangesGraph::djikstra_path(int s, int e) {
    djikstra(s);

    // ...
}