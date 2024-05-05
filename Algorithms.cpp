
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

        std::vector<int> Algorithms::bfs(const Graph& graph, int start){
            int numV = graph.getNumV();
            std::queue<int> q;
            std::vector<int> colors(numV, WHITE);
            std::vector<int> dist(numV, INFINITY);
            q.push(start);
            colors[start] = GRAY;
            dist[start] = 0;

            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v=0; v<numV; v++){
                    if(graph.getEdge(u,v) > 0){
                        if(colors[v] == WHITE){
                            if(dist[v] > dist[u] + graph.getEdge(u,v)){ dist[v] = dist[u] + graph.getEdge(u,v); }
                            colors[v] = GRAY;
                            q.push(v);
                        } else if(colors[v] == GRAY || graph.getEdge(v,u) == 0){
                            cycle_exists = 1;
                        }
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
            cycle_exists = 0;
            int numV = graph.getNumV();
            for(int i=0; i<numV; i++){
                bfs(graph, i);
                if(cycle_exists){ return TRUE; }
            }
            return FALSE;
        }

        int Algorithms::isBipartite(const Graph& graph){
            int numV = graph.getNumV();
            std::queue<int> q;
            std::vector<int> colors(numV, WHITE);
            std::vector<int> groups(numV, -1);
            for(int i=0; i<numV; i++){
                if(colors[i] == WHITE){
                    groups[i] = 0;
                    q.push(i);
                    colors[i] = GRAY;
                    while(!q.empty()){
                        int u = q.front();
                        q.pop();
                        for(int v=0; v<numV; v++){
                            if(graph.getEdge(u,v) > 0){
                                if(colors[v] == WHITE){
                                    groups[v] = !groups[i];
                                    colors[v] = GRAY;
                                    q.push(v);
                                } else if(groups[v] == groups[i]){ return FALSE; }
                            }
                        }
                        colors[u] = BLACK;
                    }
                }
            }
            return TRUE;
        }

        int Algorithms::negativeCycle(const Graph& graph){
            int numV = graph.getNumV();
            std::vector<int> dist(numV, INFINITY);
            for(int v=0; v<numV; v++){
                if(dist[v] == INFINITY){
                    dist[v] = 0;
                    for(int u=0; u<numV; u++){
                        for(int i=0; i<numV; i++){
                            for(int j=0; j<numV; j++){
                                if(dist[j] > dist[i] + graph.getEdge(i,j)){
                                    dist[j] = dist[i] + graph.getEdge(i,j);
                                }
                            }
                        }
                    }
                    for(int i=0; i<numV; i++){
                        for(int j=0; j<numV; j++){
                            if(dist[j] > dist[i] + graph.getEdge(i,j)){
                                return TRUE;
                            }
                        }
                    }
                }
            }
            return FALSE;
        }
}
