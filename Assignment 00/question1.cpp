#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct Edge {
    int dest, stamina;
};

struct State {
    int level, stamina, sleep_time;
    bool operator>(const State& other) const {
        return sleep_time > other.sleep_time;
    }
};

int dijkstra(int n, int m, int start, int end, vector<vector<Edge>>& graph, vector<pair<int, int>>& fruits) {
    vector<vector<int>> min_sleep(n + 1, vector<int>(101, INT_MAX));
    priority_queue<State, vector<State>, greater<State>> pq;

    pq.push({start, 0, 0});
    min_sleep[start][0] = 0;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        int level = current.level;
        int stamina = current.stamina;
        int sleep_time = current.sleep_time;

        if (level == end) {
            return sleep_time;
        }

        int new_stamina = fruits[level].first;
        int sleep_cost = fruits[level].second;
        if (sleep_time + sleep_cost < min_sleep[level][new_stamina]) {
            min_sleep[level][new_stamina] = sleep_time + sleep_cost;
            pq.push({level, new_stamina, sleep_time + sleep_cost});
        }
        for (auto& edge : graph[level]) {
            int next_level = edge.dest;
            int stamina_cost = edge.stamina;
            if (stamina >= stamina_cost && sleep_time < min_sleep[next_level][stamina - stamina_cost]) {
                min_sleep[next_level][stamina - stamina_cost] = sleep_time;
                pq.push({next_level, stamina - stamina_cost, sleep_time});
            }
        }
    }

    return -1;
}

int main() {
    int n, m, start, end;
    cin >> n >> m >> start >> end;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }

    vector<pair<int, int>> fruits(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> fruits[i].first >> fruits[i].second;
    }

    int result = dijkstra(n, m, start, end, graph, fruits);
    cout << result << endl;

    return 0;
}
