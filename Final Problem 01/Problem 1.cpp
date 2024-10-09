#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

class Node
{
public:
    int id;
    double prob;
    Node(int _id, double _prob) : id(_id), prob(_prob) {}
    bool operator<(const Node& other) const
    {
        return prob < other.prob;
    }
};

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
{
    vector<vector<pair<int, double>>> graph(n);
    for (int i = 0; i < edges.size(); ++i)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        double p = succProb[i];
        graph[u].emplace_back(v, p);
        graph[v].emplace_back(u, p);
    }

    vector<double> probs(n, 0.0);
    probs[start] = 1.0;

    priority_queue<Node> pq;
    pq.emplace(start, 1.0);

    while (!pq.empty())
    {
        Node node = pq.top();
        pq.pop();

        int curr = node.id;
        double currProb = node.prob;

        if (curr == end)
        {
            return currProb;
        }

        for (const auto& neighbor : graph[curr])
        {
            int next = neighbor.first;
            double nextProb = neighbor.second;

            if (probs[curr] * nextProb > probs[next])
            {
                probs[next] = probs[curr] * nextProb;
                pq.emplace(next, probs[next]);
            }
        }
    }

    return 0.0;
}

int main()
{
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    int start = 0;
    int end = 2;

    cout << fixed << setprecision(5) << maxProbability(n, edges, succProb, start, end) << endl;

    return 0;
}
