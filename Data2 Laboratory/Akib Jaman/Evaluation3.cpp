#include <bits/stdc++.h>
using namespace std;

#define INF 99999

typedef pair<int,int> edgePair;

class Graph
{
    int n;
    list<edgePair> *adj;
public:
    Graph(int n)
    {
        this->n = n;
        adj = new list<edgePair>[n];
    }

    void addEdge(int x,int y,int c)
    {
        adj[x].push_back(make_pair(x,c));
        adj[y].push_back(make_pair(y,c));
    }
    void addEdge(int a,int k)
    {
        adj[a].push_back();
        adj[k].push_back();
    }

    void Dijkstra(int src)
    {
        priority_queue<edgePair, vector<edgePair>, greater<edgePair>> pq;
        vector<int> dist(n,INF);
        vector<int> parent(n, -1);
        dist[src] = 0;
        pq.push(make_pair(src, dist[src]));

        while (!pq.empty())
        {
            int u = pq.top().first;
            pq.pop();
            for (auto i = adj[u].begin(); i != adj[u].end(); i++)
            {
                int n = (*i).first;
                int cost = (*i).second;
                if (dist[n] > dist[u] + cost)
                {
                    dist[n] = dist[u] + cost;
                    parent[n] = u;
                    pq.push(make_pair(n, dist[n]));
                }
            }
        }

    }
};

int main()
{
    int colony;
    int n, m;
    int x,y,c,q,a,k;
    cin>>colony;
    if(colony ==1 )
    {
        cin >> n;
        Graph g(n);
        cin >> m;

        for (int i = 0; i < m; i++)
        {

            cin>>x>>y>>c;
            g.addEdge(x, y, c);
        }
        g.Dijkstra(0);
        cin>>q;
        for(int i=0; i<q; i++)
        {
            cin>>a>>k;
            g.addEdge(a,k);

        }


    }
    else{
        cout<<"invalid";
    }



    return 0;
}
