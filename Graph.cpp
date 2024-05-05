
#include "Graph.hpp"
#include <vector>
#include <iostream>

namespace ariel {

    Graph::Graph() {}
    
    int Graph::getEdge(int s, int t) const {
        return mat[s][t]; 
    }
    int Graph::getNumV() const {
        return mat.size();
    }

    void Graph::loadGraph(const std::vector<std::vector<int>> graph){
        mat = graph;
    }

    void Graph::printGraph(){
        int numV = mat.size();
        int count = 0;
        for(int i=0; i<numV; i++){
            for(int j=0; j<numV; j++){
                if(mat[i][j] > 0){ count++; }
            }
            std::cout << "Graph with " << numV << " vertices and " << count << " edges." << std::endl;
        }
    }
}