#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
    int V;
    list<pair<int, int>>* adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int src);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void Graph::shortestPath(int src)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    vector<int> dist(V, INF);
    dist[src] = 1;

    pq.push({1, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int w = (*i).second;

            int prod = 1;
            for (auto j = adj[u].begin(); j != i; ++j) {
                int prev_w = (*j).second;
                prod = (prod * prev_w) % INF;
            }

            int weight = (w * prod) % INF;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main()
{
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 1, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);

    g.shortestPath(0);

    return 0;
}
