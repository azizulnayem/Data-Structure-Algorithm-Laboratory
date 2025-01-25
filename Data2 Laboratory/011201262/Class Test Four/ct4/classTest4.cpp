#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

class Graph {
private:
    int V;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int vertices) : V(vertices), adjMatrix(vertices, std::vector<int>(vertices, INF)) {}

    void addEdge(int src, int dest, int weight) {
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight; // Since the graph is undirected
    }

    void printAdjMatrix() {
        std::cout << "Weighted Adjacency Matrix:" << std::endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (adjMatrix[i][j] == INF)
                    std::cout << "INF\t";
                else
                    std::cout << adjMatrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    void dijkstra(int src, int dest) {
        std::vector<int> distance(V, INF);
        std::vector<bool> visited(V, false);
        std::vector<int> parent(V, -1);

        distance[src] = 0;

        for (int i = 0; i < V - 1; ++i) {
            int u = -1;
            for (int j = 0; j < V; ++j) {
                if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                    u = j;
                }
            }

            visited[u] = true;

            for (int v = 0; v < V; ++v) {
                if (!visited[v] && adjMatrix[u][v] != INF) {
                    int newDist = distance[u] + adjMatrix[u][v];
                    if (newDist < distance[v]) {
                        distance[v] = newDist;
                        parent[v] = u;
                    }
                }
            }
        }

        printPath(src, dest, parent);
        std::cout << "\nMinimum distance between node " << static_cast<char>('A' + src) << " and node " << static_cast<char>('A' + dest) << " is: " << distance[dest] << std::endl;
    }

    void printPath(int src, int dest, const std::vector<int>& parent) {
        if (dest == src) {
            std::cout << static_cast<char>('A' + src) << " ";
        } else if (parent[dest] == -1) {
            std::cout << "No path from " << static_cast<char>('A' + src) << " to " << static_cast<char>('A' + dest) << std::endl;
        } else {
            printPath(src, parent[dest], parent);
            std::cout << static_cast<char>('A' + dest) << " ";
        }
    }
};

int main() {
    Graph graph(6);
    graph.addEdge(0, 1, 3);
    graph.addEdge(1, 4, 6);
    graph.addEdge(4, 2, 9);
    graph.addEdge(0, 3, 8);
    graph.addEdge(3, 5, 2);
    graph.addEdge(5, 2, 3);
    graph.addEdge(1, 3, 5);
    graph.addEdge(3, 4, 3);
    graph.addEdge(4, 5, 1);

    graph.printAdjMatrix();
    graph.dijkstra(0, 2);

    return 0;
}
