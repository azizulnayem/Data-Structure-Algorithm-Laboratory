#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int INF = 1e9;

struct Order {
    int start, end, weight, profit;
};

vector<vector<pair<int, int>>> graph;
vector<Order> orders;
vector<int> path;
vector<int> bestPath;
int maxProfit = -1; // Initialize maxProfit with a negative value

void dfs(int u, int fuel, int weight, int profit, vector<int>& currentPath, int W) {
    if (fuel < 0 || weight > W) return;

    if (u == destination) { // Change D to the appropriate variable name
    if (profit > maxProfit) {
        maxProfit = profit;
        bestPath = currentPath;
    }
    return;
}

    for (auto& edge : graph[u]) {
        int v = edge.first;
        int distance = edge.second;

        if (find(currentPath.begin(), currentPath.end(), v) == currentPath.end()) {
            currentPath.push_back(v);
            dfs(v, fuel - distance, weight, profit, currentPath, W);
            currentPath.pop_back();
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int Xi, Yi, Zi;
        cin >> Xi >> Yi >> Zi;
        graph[Xi].push_back({Yi, Zi});
        graph[Yi].push_back({Xi, Zi});
    }

    int K;
    cin >> K;

    orders.resize(K);

    for (int i = 0; i < K; ++i) {
        cin >> orders[i].start >> orders[i].end >> orders[i].weight >> orders[i].profit;
    }

    int S, D, W;
    cin >> S >> D >> W;

    vector<int> initialPath = {S};
    set<int> visitedNodes; // Keep track of visited nodes

    dfs(S, W, 0, 0, initialPath, W);

    vector<int> finalOrders;

    for (int i = 0; i < bestPath.size() - 1; ++i) {
        for (int j = 0; j < K; ++j) {
            if (orders[j].start == bestPath[i] && orders[j].end == bestPath[i + 1]) {
                finalOrders.push_back(j);
                break;
            }
        }
    }

    cout << finalOrders.size() << endl;

    for (int i = 0; i < bestPath.size() - 1; ++i) {
        cout << "0 " << bestPath[i + 1] << endl;
    }

    set<int> takenOrders;

    for (int i = 0; i < finalOrders.size(); ++i) {
        int orderId = finalOrders[i];

        if (takenOrders.count(orderId) == 0) {
            cout << "1 " << orderId + 1 << endl;
            takenOrders.insert(orderId);
        }

        cout << "2 " << orderId + 1 << endl;
    }

    return 0;
}
