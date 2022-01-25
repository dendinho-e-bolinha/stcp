#include "graphs/least_distance.h"

#include <stdexcept>

using namespace std;

LeastDistanceGraph::LeastDistanceGraph(int n) : n(n), nodes(n + 1) {}

void LeastDistanceGraph::add_edge(int src, int dest, double distance) {
    if (src < 1 || dest < 1 || src > n || dest > n)
        throw invalid_argument("src or dest out of bounds");

    nodes[src].adj.push_back({ dest, distance });
}

void LeastDistanceGraph::djikstra(int s) {
    // ...
}