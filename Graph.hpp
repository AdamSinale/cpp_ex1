#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> mat;

    public:
        Graph();
        int getEdge(int s, int t);
        int getNumV();
        void loadGraph(const std::vector<std::vector<int>> graph);
        void printGraph();
    };
}
#endif