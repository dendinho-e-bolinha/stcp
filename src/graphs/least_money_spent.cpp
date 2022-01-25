#include "graphs/least_money_spent.h"

#include <stdexcept>

using namespace std;

LeastMoneySpentGraph::LeastMoneySpentGraph(int n, vector<string> zones) : n(n), nodes(n + 1) {
    for (int i = 1; i <= n; i++) {
        nodes[i].zone = zones.at(i - 1);
    }
}

void LeastMoneySpentGraph::add_edge(int src, int dest) {
    if (src < 1 || dest < 1 || src > n || dest > n)
        throw invalid_argument("src or dest out of bounds");

    nodes[src].adj.push_back({ dest });
}

void LeastMoneySpentGraph::djikstra(int s) {
    // ...
}