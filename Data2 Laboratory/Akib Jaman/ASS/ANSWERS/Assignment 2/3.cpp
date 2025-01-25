#include<bits/stdc++.h>
using namespace std;

# define INF 9999999

typedef pair<int, int> edgeWeightPair;

class Graph
{
    int v;
    list<edgeWeightPair> *adj;

public:
    Graph(int v) ///Constructor
    {
        this->v = v;
        adj = new list<edgeWeightPair> [v];
    }
    void addEdge(int u, int v, int w) ///adjacency List Development
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    void Dijkstra(int src, int dest, int time)
    {
        priority_queue< edgeWeightPair, vector <edgeWeightPair>, greater<edgeWeightPair> > pq;
        vector<int> dist(v, INF);
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
        if(time - 2 * dist[dest] > 0)
        {
            cout << time - 2 * dist[dest] << std::endl;
        }
        else
        {
            cout << 0 << std::endl;
        }

    }
};
int main()
{
    int N, M, T, X, Y, C, Q, A, K;
    int source = 2;
    cin >> T;

    for(int i = 0; i < T; ++i)
    {
        cin >> N >> M;
        Graph g(N);
        for(int j = 0; j < M; ++j)
        {
            cin >> X >> Y >> C;
            g.addEdge(X - 1, Y - 1, C);
        }
        cin >> Q;
        for(int j = 0; j < Q; ++j)
        {
            cin >> A >> K;
            g.Dijkstra(source, A - 1, K);
        }
    }


    return 0;
}

