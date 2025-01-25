#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

class UnionFind {
    private:
        vector<int> parent, rank;
    public:
        UnionFind(int n) {
            rank.assign(n+1, 0);
            parent.resize(n+1);
            for (int i = 1; i <= n; ++i)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return;
            if (rank[x] < rank[y]) swap(x, y);
            parent[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }

        bool same(int x, int y) {
            return find(x) == find(y);
        }
};

int main() {
    freopen("input.txt", "r", stdin); // open input file
    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), cmp);

    UnionFind uf(n);
    vector<Edge> mst;
    int mst_cost = 0;
    for (auto e : edges) {
        if (!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
            mst.push_back(e);
            mst_cost += e.w;
        }
    }

    cout << "MST Edges:\n";
    for (auto e : mst)
        cout << e.u << " " << e.v << "\n";
    cout << "Minimum weight of MST = " << mst_cost << "\n";

    return 0;
}
