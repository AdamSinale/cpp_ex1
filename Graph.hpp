#pragma once

#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

namespace ariel {
    class Graph {
    private:
        vector<vector<int>> mat;

    public:
        Graph();
        int getEdge(unsigned int s, unsigned int t) const;
        unsigned int getNumV() const;
        void loadGraph(const vector<vector<int>> graph);
        void printGraph();
    };
}
