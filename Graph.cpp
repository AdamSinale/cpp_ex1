
#include "Graph.hpp"
#include <vector>
#include <iostream>

namespace ariel {

    Graph::Graph() {}
    
    int Graph::getEdge(unsigned int s, unsigned int t) const {
        if (s<0 && s>=getNumV() && t < 0 && t>=getNumV()){
            return -1;
        }
        return mat[s][t]; 
    }
    unsigned int Graph::getNumV() const {
        return mat.size();
    }

    void Graph::loadGraph(const vector<vector<int>> graph){
        mat = graph;
    }

    void Graph::printGraph(){
        unsigned int numV = mat.size();
        int count = 0;
        for(unsigned int i=0; i<numV; i++){
            for(unsigned int j=0; j<numV; j++){
                if(mat[i][j] > 0){ count++; }
            }
            cout << "Graph with " << numV << " vertices and " << count << " edges." << endl;
        }
    }
}