#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
# define INF 99999999

typedef pair<int, int> edgeWeightpair;

class Graph
{
    int V;
    list<edgeWeightpair> *adj;

public:
    Graph(int V)
    {
        this->V=V;
        adj=new list<edgeWeightpair> [V];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    void primMST()
    {
        priority_queue< edgeWeightpair, vector <edgeWeightpair> , greater<edgeWeightpair> > pq;
        int src = 0;
        vector<int> key(V, INF);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);
        pq.push(make_pair(0, src));
        key[src] = 0;
        while (!pq.empty()) /// While The PQ is not Empty
        {
            int u = pq.top().second; /// catch the top element of PQ
            pq.pop(); /// Remove the top element of PQ
            if(inMST[u] == true) /// Sanity check ( if the element is already visited)
            {
                continue;
            }
            inMST[u] = true;
            list< pair<int, int> >::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i) ///Exploring all the adjacency vertex of the element
            {
                int v = (*i).first;
                int weight = (*i).second;
                if (inMST[v] == false && weight < key [v]) /// (if it is already visited and if the current explored weight is less than the previously recorded weight)
                {

                    key[v] = weight; /// key Update with current explored weight
                    pq.push(make_pair(key[v], v)); /// push the (weight, vertex) PQ
                    parent[v] = u; /// parent update
                }
            }
        }
        for (int i = 0; i < V; i++){
            if (i==0) continue;
            cout<< parent[i] << " <---- " << key[i] << " ---> " << i << endl;
        }


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
    g.primMST();

    return 0;
}
