#pragma once

#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Graph {
    struct Edge {
        int dest;   
        int weight; 

        string line;
    };

    struct Node {
        list<Edge> adj;

        int parent;
        int parent_edge;
        bool visited;

        int dist;

        string code;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool has_dir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented

    // void dijkstra_(int s);

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void add_edge(int src, int dest, int weight = 1);
};
