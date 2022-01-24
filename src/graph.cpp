#include "graph.h"

#include <limits>
#include <functional>
#include "minHeap.h"

#define INF numeric_limits<int>::max() / 2

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), has_dir(dir), nodes(num+1) {}

// Add edge from source to destination with a certain weight
void Graph::add_edge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!has_dir) nodes[dest].adj.push_back({src, weight});
}

// void Graph::dijkstra(int s) {
//     for (int i = 1; i <= n; i++) {
//         Node &node = nodes.at(i);

//         node.dist = INF;
//         node.parent = 0;
//         node.visited = false;
//     }

//     MinHeap<int, int> minHeap(n, 0);
//     minHeap.insert(s, 0);
    
//     nodes.at(s).dist = 0;

//     while (minHeap.getSize() > 0) {
//         int parent = minHeap.removeMin();
//         Node &node = nodes.at(parent);
//         node.visited = true;

//         for (const Edge &edge : node.adj) {
//             Node &child = nodes.at(edge.dest);
//             if (child.visited) continue;

//             int dist = node.dist + edge.weight;
//             if (child.dist > dist) {
//                 child.dist = dist;
//                 child.parent = parent;

//                 if (minHeap.hasKey(edge.dest)) minHeap.decreaseKey(edge.dest, dist);
//                 else minHeap.insert(edge.dest, dist);
//             }
//         }
//     }
// }