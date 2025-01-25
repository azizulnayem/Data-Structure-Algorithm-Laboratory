#include <iostream>
#include <queue>

class Graph {
private:
    int numVertices;
    int** adjMatrix;

public:
    Graph(int vertices);
    ~Graph();

    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

Graph::Graph(int vertices) : numVertices(vertices) {
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::addEdge(int src, int dest) {
    if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // For undirected graph, we set both entries to 1.
    } else {
        std::cerr << "Error: Invalid vertex indices.\n";
    }
}

void Graph::BFS(int startVertex) {
    if (startVertex < 0 || startVertex >= numVertices) {
        std::cerr << "Error: Invalid start vertex index.\n";
        return;
    }

    std::vector<bool> visited(numVertices, false);
    std::queue<int> queue;

    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        int currentVertex = queue.front();
        std::cout << currentVertex << " ";
        queue.pop();

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }

    std::cout << std::endl;
}

int main() {
    int numVertices = 6;
    Graph graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    std::cout << "Breadth-First Search (BFS) starting from vertex 0: ";
    graph.BFS(0);

    return 0;
}
