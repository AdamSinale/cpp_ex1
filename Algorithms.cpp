
#include "Algorithms.hpp"

#define TRUE 1
#define FALSE 0

#define WHITE -1
#define GRAY 0
#define BLACK 1

#define INFINITY 2147483647     //maximum integer posibble
namespace ariel {

        vector<unsigned int> Algorithms::bfs(const Graph& graph, unsigned int start){
            unsigned int numV = graph.getNumV();
            queue<unsigned int> q;
            vector<int> colors(numV, WHITE);
            vector<int> dist(numV, INFINITY);
            vector<unsigned int> parent(numV, UINT_MAX);
            q.push(start);
            colors[start] = GRAY;
            dist[start] = 0;
            while(!q.empty()){
                unsigned int u = q.front();
                q.pop();
                for(unsigned int v=0; v<numV; v++){
                    if(graph.getEdge(u,v) > 0){
                        if(colors[v] == WHITE){
                            if(dist[v] > dist[u] + graph.getEdge(u,v)){ 
                                dist[v] = dist[u] + graph.getEdge(u,v);
                                parent[v] = u;
                            }
                            colors[v] = GRAY;
                            q.push(v);
                        }
                    }
                }
                colors[u] = BLACK;
            }
            return parent;
        }

        int Algorithms::isConnected(const Graph& graph){
            unsigned int numV = graph.getNumV();
            for(unsigned int i=0; i<numV; i++){
                vector<unsigned int> parent = bfs(graph, i);
                for(unsigned int j=0; j<numV; j++){
                    if(parent[j] == UINT_MAX){ return FALSE; }
                }
            }
            return TRUE;
        }

        string Algorithms::shortestPath(const Graph& graph, unsigned int start, unsigned int end){
            vector<unsigned int> parent = bfs(graph, start);
            if(parent[end] == INFINITY){ return "-1"; }
            unsigned int cur = end;
            string path = std::to_string(cur);
            while(parent[cur] != UINT_MAX){
                path = std::to_string(parent[cur]) + "->" + path;
                cur = parent[cur];
            }
            return path;
        }

        string Algorithms::isContainsCycle(const Graph& graph){
            unsigned int numV = graph.getNumV();
            queue<unsigned int> q;
            vector<int> colors(numV, WHITE);
            vector<int> dist(numV, INFINITY);
            vector<unsigned int> parent(numV, UINT_MAX);
            for(unsigned int i=0; i<numV; i++){
                q.push(i);
                colors[i] = GRAY;
                dist[i] = 0;
                while(!q.empty()){
                    unsigned int u = q.front();
                    q.pop();
                    for(unsigned int v=0; v<numV; v++){
                        if(graph.getEdge(u,v) > 0){
                            if(colors[v] == WHITE){
                                if(dist[v] > dist[u] + graph.getEdge(u,v)){ 
                                    dist[v] = dist[u] + graph.getEdge(u,v);
                                    parent[v] = u;
                                }
                                colors[v] = GRAY;
                                q.push(v);
                            } else if(colors[v] == GRAY || graph.getEdge(v,u) == 0){
                                unsigned int cur = v;
                                string path = std::to_string(cur);
                                while(parent[cur] != v){
                                    path = std::to_string(parent[cur]) + "->" + path;
                                    cur = parent[cur];
                                }
                                path += "->" + std::to_string(cur);
                                return "The cycle is: " + path;
                            }
                        }
                    }
                    colors[u] = BLACK;
                }
            }
            return "0";
        }

        string Algorithms::isBipartite(const Graph& graph){
            unsigned int numV = graph.getNumV();
            queue<unsigned int> q;
            vector<int> colors(numV, WHITE);
            vector<int> groups(numV, -1);
            for(unsigned int i=0; i<numV; i++){
                if(colors[i] == WHITE){
                    groups[i] = 0;
                    q.push(i);
                    colors[i] = GRAY;
                    while(!q.empty()){
                        unsigned int u = q.front();
                        q.pop();
                        for(unsigned int v=0; v<numV; v++){
                            if(graph.getEdge(u,v) > 0){
                                if(colors[v] == WHITE){
                                    groups[v] = !groups[i];
                                    colors[v] = GRAY;
                                    q.push(v);
                                } else if(groups[v] == groups[i]){ return "0"; }
                            }
                        }
                        colors[u] = BLACK;
                    }
                }
            }
            string A = "";
            string B = "";
            for(unsigned int i=0; i<numV; i++){
                if(groups[i] == 0){ 
                    if (A.empty()) { A += std::to_string(i); }
                    A += ", " + std::to_string(i); 
                }
                else{ 
                    if (B.empty()) { B += std::to_string(i); }
                    B += ", " + std::to_string(i); 
                }
            }
            return "The graph is bipartite: A={"+A+"}, B={"+B+"}";
        }

        int Algorithms::negativeCycle(const Graph& graph){
            unsigned int numV = graph.getNumV();
            vector<int> dist(numV, INFINITY);
            for(unsigned int v=0; v<numV; v++){
                if(dist[v] == INFINITY){
                    dist[v] = 0;
                    for(unsigned int u=0; u<numV; u++){
                        for(unsigned int i=0; i<numV; i++){
                            for(unsigned int j=0; j<numV; j++){
                                if(dist[j] > dist[i] + graph.getEdge(i,j)){
                                    dist[j] = dist[i] + graph.getEdge(i,j);
                                }
                            }
                        }
                    }
                    for(unsigned int i=0; i<numV; i++){
                        for(unsigned int j=0; j<numV; j++){
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
