#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v;
};

int find(int u, vector<int>& parent) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u], parent);
}

void union_sets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = find(u, parent);
    v = find(v, parent);

    if (u != v) {
        if (rank[u] < rank[v])
            swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v])
            rank[u]++;
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    vector<Edge> edges(b);
    vector<int> parent(a + 1), rank(a + 1, 0);

    for (int i = 1; i <= a; ++i)
        parent[i] = i;

    for (int i = 0; i < b; ++i) {
        cin >> edges[i].u >> edges[i].v;
    }

    int drivers_needed = 0;
    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        if (find(u, parent) != find(v, parent)) {
            union_sets(u, v, parent, rank);
            drivers_needed++;
        }
    }
    cout << drivers_needed << endl;

    return 0;
}
