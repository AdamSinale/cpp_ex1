#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> mat;

public:
    Graph();
    void loadGraph(const std::vector<std::vector<int>> mat);
    void printGraph();
};

#endif