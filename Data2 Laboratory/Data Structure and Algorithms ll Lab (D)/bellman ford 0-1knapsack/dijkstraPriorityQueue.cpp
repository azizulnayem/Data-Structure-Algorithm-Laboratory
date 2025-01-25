#include<bits/stdc++.h>
using namespace std;

# define INF 9999999

typedef pair<int, int> edgeWeightPair;

class Graph
{
    int V;
    list<edgeWeightPair> *adj;

public:
    Graph(int V) ///Constructer
    {
        this->V = V;
        adj = new list<edgeWeightPair> [V];
    }
    void addEdge(int u, int v, int w) ///adjacency List Development
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    void Dijkstra(int src)
    {
        priority_queue< edgeWeightPair, vector <edgeWeightPair> , greater<edgeWeightPair> > pq;
        vector<int> dist(V, INF);
        ///vector<int> parent(V, -1);
        pq.push(make_pair(0, src));
        dist[src] = 0;
        while (!pq.empty()) ///while(PQ is not empty)
        {
            int u = pq.top().second; ///u = PQ.top.second() ///u=src
            pq.pop();
            list< pair<int, int> >::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i) ///for(all the adjacent pairs  i ----> begin--end)
            {
                int v = (*i).first;
                int weight = (*i).second;
                if (dist[v] > dist[u] + weight) ///Relaxation
                {
                    dist[v] = dist[u] + weight; /// dist[v] UPDATE
                    ///parent[v] = u;
                    pq.push(make_pair(dist[v], v)); ///PUSH INTO PQ
                }
            }
        }
        printf("Vertex Distance from Source: \n");
        for (int i = 0; i < V; ++i)
            printf("%d  ----------->  %d\n", i, dist[i]);
    }
};
int main()
{
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.Dijkstra(0);

    return 0;
}
