#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

class Graph {
private:
    std::unordered_map<int, std::vector<int>> adjList;

public:
    void addEdge(int src, int dest);
    bool hasPath(int start, int end, const std::string& algorithm);
    bool DFS(int start, int end);
    bool BFS(int start, int end);
};

void Graph::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
}

bool Graph::hasPath(int start, int end, const std::string& algorithm) {
    if (algorithm == "DFS") {
        return DFS(start, end);
    } else if (algorithm == "BFS") {
        return BFS(start, end);
    } else {
        std::cerr << "Error: Invalid algorithm. Please use 'BFS' or 'DFS'.\n";
        return false;
    }
}

bool Graph::DFS(int start, int end) {
    std::stack<int> stack;
    std::unordered_map<int, bool> visited;

    stack.push(start);
    visited[start] = true;

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        if (current == end) {
            return true;
        }

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                stack.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false;
}

bool Graph::BFS(int start, int end) {
    std::queue<int> queue;
    std::unordered_map<int, bool> visited;

    queue.push(start);
    visited[start] = true;

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        if (current == end) {
            return true;
        }

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                queue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    Graph graph;
    for (int i = 0; i < m; i++) {
        int src, dest;
        std::cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    int p, q;
    std::cin >> p >> q;

    std::string algorithm;
    std::cin >> algorithm;

    bool result = graph.hasPath(p, q, algorithm);
    std::cout << (result ? "True" : "False") << std::endl;

    return 0;
}
