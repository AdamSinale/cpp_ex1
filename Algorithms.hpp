#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <vector>

namespace algorithms {

    int isConnected(const Graph& graph);

    int shortestPath(const Graph& graph, int start, int end);

    int isContainsCycle(const Graph& graph);

    int isBipartite(const Graph& graph);

    int negativeCycle(const Graph& graph);

}

#endif