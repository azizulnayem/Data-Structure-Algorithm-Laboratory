#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <bitset>

using namespace std;

const int MAX_V = 1000;

vector<int> graph[MAX_V];
bitset<MAX_V> visited;

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    ///freopen("input.txt", "r", stdin);
    freopen("input2.txt", "r", stdin);

    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; ++i) {
        int s, d;
        cin >> s >> d;
        graph[s].push_back(d);
    }

    int C;
    cin >> C;

    vector<int> shortlist;
    for (int i = 0; i < C; ++i) {
        int city;
        cin >> city;
        shortlist.push_back(city);
    }

    bool canVisitAllCities = false;

    for (int city : shortlist) {
        visited.reset();
        dfs(city);
        if (visited.count() == V) {
            canVisitAllCities = true;
            break;
        }
    }

    if (canVisitAllCities) {
        cout << "Exist!" << endl;
    } else {
        cout << "Not Exist!" << endl;
    }

    return 0;
}
