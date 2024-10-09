#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
{
    vector<vector<pair<int, double>>> graph(n);
    for (int i = 0; i < edges.size(); ++i)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        double prob = succProb[i];
        graph[a].emplace_back(b, prob);
        graph[b].emplace_back(a, prob);
    }
    vector<double> probabilities(n, 0.0);
    probabilities[start] = 1.0;
    priority_queue<pair<double, int>> pq;
    pq.emplace(1.0, start);
    while (!pq.empty())
    {
        double prob = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();
        if (currNode == end)
        {
            return prob;
        }
        for (const auto& neighbor : graph[currNode])
        {
            int nextNode = neighbor.first;
            double nextProb = neighbor.second * prob;
            if (nextProb > probabilities[nextNode])
            {
                probabilities[nextNode] = nextProb;
                pq.emplace(nextProb, nextNode);
            }
        }
    }
    return 0.0;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    vector<double> succProb(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i][0] >> edges[i][1] >> succProb[i];
    }
    int start, end;
    cin >> start >> end;
    double result = maxProbability(n, edges, succProb, start, end);
    cout << fixed << setprecision(5) << result << endl;
    return 0;
}
