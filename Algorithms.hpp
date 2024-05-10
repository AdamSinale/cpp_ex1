#pragma once

#include "Graph.hpp"
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <climits>

using std::cout;
using std::endl;
using std::queue;
using std::string;
using std::vector;
using namespace ariel;

namespace ariel
{

    class Algorithms
    {
    public:
        static vector<unsigned int> bfs(const Graph &graph, unsigned int start);

        static int isConnected(const Graph &graph);

        static string shortestPath(const Graph &graph, unsigned int start, unsigned int end);

        static string isContainsCycle(const Graph &graph);

        static string isBipartite(const Graph &graph);

        static int negativeCycle(const Graph &graph);
    };
}
