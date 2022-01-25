#include "dijkstra.h"

#include <iostream>

using namespace std;

namespace dijkstra {
void djikstra(int s) {
        for (int i = 1; i <= n; i++) {
            nodes[i].search = { 0, 999999, false };

            SearchInfo& search = nodes[i].search;
            if (search.distance < 10)
                search.distance = 10;
                
            std::cout << nodes[i].search.parent << std::endl;
            std::cout << nodes[i].search.distance << std::endl;
            std::cout << nodes[i].search.visited << std::endl;
        }
    }
}


    list<int> djikstra_route(int s, int e) {
        djikstra(s);

        if (nodes[e].search.distance == -1)
            return {};

        list<string> route;

        while (nodes[i])
    }