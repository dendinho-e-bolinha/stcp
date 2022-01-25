#include "graphs/least_stops.h"

#include <stdexcept>

using namespace std;

LeastStopsGraph::LeastStopsGraph(int n) : n(n), nodes(n + 1) {}

void LeastStopsGraph::add_edge(int src, int dest) {
    if (src < 1 || dest < 1 || src > n || dest > n)
        throw invalid_argument("src or dest out of bounds");

    nodes[src].adj.push_back({ dest });
}