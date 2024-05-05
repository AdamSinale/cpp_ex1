
#include "Algorithms.hpp"
#include <vector>
#include <queue>

#define TRUE 1
#define FALSE 0

#define WHITE -1
#define GRAY 0
#define BLACK 1

#define INFINITY 2147483647     //maximum integer posibble
namespace ariel {
    namespace Algorithms {

        std::vector<int> bfs(const Graph& graph, int start){
            int numV = graph.getNumV();
            std::queue<int> q;
            std::vector<int> colors(numV, WHITE);
            std::vector<int> dist(numV, INFINITY);
            std::vector<int> prev(numV, -1);
            q.push(start);
            colors[start] = GRAY;
            dist[start] = 0;

            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int i=0; i<numV; i++){
                    if(graph.getEdge(u,i) > 0 && colors[i] == WHITE){
                        if(dist[i] > dist[u] + graph.getEdge(u,i)){ dist[i] =dist[u] + graph.getEdge(u,i); }
                        colors[i] = GRAY;
                        q.push(i);
                    }
                }
                colors[u] = BLACK;
            }
            return dist;
        }

        int Algorithms::isConnected(const Graph& graph){
            int numV = graph.getNumV();
            for(int i=0; i<numV; i++){
                std::vector<int> dist = bfs(graph, i);
                for(int j=0; j<numV; j++){
                    if(dist[j] == INFINITY){ return FALSE; }
                }
            }
            return TRUE;
        }

        int Algorithms::shortestPath(const Graph& graph, int start, int end){
            std::vector<int> dist = bfs(graph, start);
            if(dist[end] == INFINITY){ return -1; }
            return dist[end];
        }

        int Algorithms::isContainsCycle(const Graph& graph){
            int numV = graph.getNumV();
            for(int i=0; i<numV; i++){
                //   אם ביאפאס יפגוש שחור יש מעגל
            }
        }

        int Algorithms::isBipartite(const Graph& graph){

        }

        int Algorithms::negativeCycle(const Graph& graph){

        }
    }
}
