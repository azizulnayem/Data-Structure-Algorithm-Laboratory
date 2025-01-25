#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& adjList, int vertex, vector<bool>& visited, vector<bool>& reachable);

int findRootVertex(const vector<vector<int>>& adjList) {
    int numVertices = adjList.size();
    vector<bool> visited(numVertices, false);

    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            bool isRoot = true;
            vector<bool> reachable(numVertices, false);
            dfs(adjList, i, visited, reachable);

            for (int j = 0; j < numVertices; ++j) {
                if (!reachable[j]) {
                    isRoot = false;
                    break;
                }
            }

            if (isRoot) {
                return i;
            }
        }
    }

    return -1; // No root vertex found
}

void dfs(const vector<vector<int>>& adjList, int vertex, vector<bool>& visited, vector<bool>& reachable) {
    visited[vertex] = true;
    reachable[vertex] = true;

    for (int neighbor : adjList[vertex]) {
        if (!visited[neighbor]) {
            dfs(adjList, neighbor, visited, reachable);
        }
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<vector<int>> adjList(numVertices);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    int rootVertex = findRootVertex(adjList);

    if (rootVertex != -1) {
        cout << "Root vertex of the directed graph: " << rootVertex << endl;
    } else {
        cout << "No root vertex found in the directed graph." << endl;
    }

    return 0;
}
