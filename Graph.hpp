#pragma once

#include <vector>
#include <iostream>
using namespace std;

namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> mat;

    public:
        Graph();
        int getEdge(int s, int t) const;
        int getNumV() const;
        void loadGraph(const std::vector<std::vector<int>> graph);
        void printGraph();
    };
}
