#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

const int INF = std::numeric_limits<int>::max();

class Graph {
private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> adjList;

public:
    void addEdge(int src, int dest, int weight) {
        adjList[src].emplace_back(dest, weight);
        adjList[dest].emplace_back(src, weight); // Since the graph is undirected
    }

    void printAdjMatrix(int V) {
        std::vector<std::vector<int>> adjMatrix(V, std::vector<int>(V, INF));

        for (const auto& entry : adjList) {
            int src = entry.first;
            for (const auto& neighbor : entry.second) {
                int dest = neighbor.first;
                int weight = neighbor.second;
                adjMatrix[src][dest] = weight;
            }
        }

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
        std::vector<int> distance(adjList.size(), INF);
        std::vector<int> parent(adjList.size(), -1);
        distance[src] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push(std::make_pair(0, src));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                    pq.push(std::make_pair(distance[v], v));
                }
            }
        }

        printPath(src, dest, parent);
        std::cout << "Minimum distance between node " << static_cast<char>('A' + src) << " and node " << static_cast<char>('A' + dest) << " is: " << distance[dest] << std::endl;
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
    Graph graph;
    graph.addEdge(0, 1, 3);
    graph.addEdge(1, 4, 6);
    graph.addEdge(4, 2, 9);
    graph.addEdge(0, 3, 8);
    graph.addEdge(3, 5, 2);
    graph.addEdge(5, 2, 3);
    graph.addEdge(1, 3, 5);
    graph.addEdge(3, 4, 3);
    graph.addEdge(4, 5, 1);

    int V = 6;
    graph.printAdjMatrix(V);
    graph.dijkstra(0, 2);

    return 0;
}

