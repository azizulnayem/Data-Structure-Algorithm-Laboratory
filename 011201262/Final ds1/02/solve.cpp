#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000;

int V, E;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

bool isGraphConnected() {
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);  // Replace "input.txt" with your input file name
    freopen("input2.txt", "r", stdin);  // Replace "input.txt" with your input file name
    // freopen("output.txt", "w", stdout);  // Uncomment this line to redirect output to a file

    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    bool isConnected = true;
    for (int start = 0; start < V; ++start) {
        fill(visited, visited + V, false);
        dfs(start);
        if (!isGraphConnected()) {
            isConnected = false;
            break;
        }
    }

    if (isConnected) {
        cout << "Gráfico completamente conectado" << endl;
    } else {
        cout << "Gráfico no completamente conectado" << endl;
    }

    return 0;
}
