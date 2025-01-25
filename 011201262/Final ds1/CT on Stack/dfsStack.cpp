#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int V = 100; // Maximum number of vertices

vector<int> adj[V]; // Adjacency list representation
bool visited[V] = {false}; // Array to track visited nodes

void dfs(int source) {
    stack<int> st;
    vector<int> visitedSequence; // To store the visited sequence
    
    st.push(source);
    
    while (!st.empty()) {
        int visiting = st.top();
        st.pop();
        
        if (visited[visiting]) {
            continue; // Skip already visited nodes
        }
        
        visited[visiting] = true;
        visitedSequence.push_back(visiting);
        
        for (int neighbor : adj[visiting]) {
            if (!visited[neighbor]) {
                st.push(neighbor); // Push non-visited adjacent nodes
            }
        }
    }
    
    cout << "Visited Sequence: ";
    for (int node : visitedSequence) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;
    
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming an undirected graph
    }
    
    int source;
    cout << "Enter the source vertex: ";
    cin >> source;
    
    dfs(source);
    
    return 0;
}
