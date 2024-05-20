// ID: 322453689
// MAIL: adam.sinale@gmail.com


# Graph Algorithms Explanations

This project includes a  `Graph` class and it's common algorithms. It is implemented in C++ and supports both directed and undirected graphs, negative and positive edges, weighted or not.

## Graph Class:

implements the fuctions need to implement comfortably the Algorithms functionss.
The Graph is represented as a matrix and given in each Algorithm function.

**Constructor: Graph():**
Initializes a new instance of the Graph class.

**loadGraph(matrix):**
loads the given matrix to the graph object.

**getEdge(i, j):**
Returns the edge between i and j.

**getNumV():**
Returns the number of vertices.

**isDirected():**
Returns 1 if the graph is considered directed and 0 if not.

**check_borders(s,f):**
Checks wether the given verices exist in the graph.

**printGraph():**
Prints the graph's info- num of vertices and edges.

## Algorithms Library


**isConnected(Graph graph)**:
checks whether a graph is connected by going over all the vertices and contucting bfs search from each of them checking if one of them doesnt reach another.

**isBipartite(Graph &graph)**:
checks whether we can split the graph into 2 groups with no edges between a single group's vertices. Does that by going through every SCC and doing bfs, if the current vertex is of groups A, its neibors of group B and when it is already A we return false.

**shortestPath(Graph graph, start, finish)**:
Finds the shortest path using bellman ford algorithm, going n-1 times and when we do for the nth time, if there is a cycle we check if it's a part of the path and if so return "-1", else we return the path.

**isContainsCycle(Graph &graph)**:
We run a dfs algorithm from each vertex that will return the paths from him to everyone. the moment one of them returns a path where a vector's parent is the starting vertex(and when undirected not his direct son) it means we have a cycle and return true.

**negativeCycle(Graph graph)**:
We run bellman for n times. on the nth time when there is a changed distance and its not a direct son in a undirected graph we go through the changed vertex until we visit him again, if we never do- there is another negative sub-cycle and we will return him.

