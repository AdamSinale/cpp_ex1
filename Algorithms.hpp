#pragma once

#include "Graph.hpp"
#include <vector>
#include <iostream>
using namespace std;
using namespace ariel;

namespace ariel {
    
    class Algorithms {
    private:
       static int cycle_exists;

    public:
        static std::vector<int> bfs(const Graph& graph, int start);

        static int isConnected(const Graph& graph);

        static int shortestPath(const Graph& graph, int start, int end);

        static int isContainsCycle(const Graph& graph);

        static int isBipartite(const Graph& graph);

        static int negativeCycle(const Graph& graph);

    };
}

