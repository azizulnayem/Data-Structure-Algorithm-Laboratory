#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Order {
    int pickup;
    int deliver;
    int weight;
    int profit;
};

vector<pair<int, int>> adjacency[1001];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        adjacency[X].push_back({Y, Z});
        adjacency[Y].push_back({X, Z});
    }

    int K;
    cin >> K;
    vector<Order> orders(K);

    for (int i = 0; i < K; ++i) {
        cin >> orders[i].pickup >> orders[i].deliver >> orders[i].weight >> orders[i].profit;
    }

    int S, D, W;
    cin >> S >> D >> W;

    vector<pair<int, int>> operations;
    int cur_junction = S;
    int fuel_left = D;
    int weight_carried = 0;
    int profit = 0;
    vector<Order> parcels;

    while (!parcels.empty() || !orders.empty()) {
        if (!parcels.empty()) {
            vector<int> to_deliver;
            for (int idx = 0; idx < parcels.size(); ++idx) {
                if (cur_junction == parcels[idx].deliver) {
                    to_deliver.push_back(idx);
                    profit += parcels[idx].profit;
                }
            }

            for (int i = to_deliver.size() - 1; i >= 0; --i) {
                parcels.erase(parcels.begin() + to_deliver[i]);
            }
        }

        if (parcels.empty()) {
            int max_profit = 0;
            int best_order_idx = -1;
            int best_deliver = -1;

            for (int idx = 0; idx < orders.size(); ++idx) {
                if (weight_carried + orders[idx].weight <= W && cur_junction == orders[idx].pickup) {
                    if (orders[idx].profit > max_profit) {
                        max_profit = orders[idx].profit;
                        best_order_idx = idx;
                        best_deliver = orders[idx].deliver;
                    }
                }
            }

            if (best_order_idx != -1) {
                operations.push_back({1, best_order_idx + 1});
                weight_carried += orders[best_order_idx].weight;
                cur_junction = best_deliver;
                parcels.push_back(orders[best_order_idx]);
                orders.erase(orders.begin() + best_order_idx);
            } else {
                int best_neighbour = -1;
                int best_distance = 1e9;
                for (auto [neighbour, distance] : adjacency[cur_junction]) {
                    if (distance <= fuel_left && distance < best_distance) {
                        best_distance = distance;
                        best_neighbour = neighbour;
                    }
                }

                if (best_neighbour != -1) {
                    operations.push_back({0, best_neighbour});
                    cur_junction = best_neighbour;
                    fuel_left -= best_distance;
                } else {
                    break;
                }
            }
        } else {
            int best_neighbour = -1;
            int best_distance = 1e9;
            for (auto [neighbour, distance] : adjacency[cur_junction]) {
                if (distance <= fuel_left && distance < best_distance) {
                    best_distance = distance;
                    best_neighbour = neighbour;
                }
            }

            if (best_neighbour != -1) {
                operations.push_back({0, best_neighbour});
                cur_junction = best_neighbour;
                fuel_left -= best_distance;
            } else {
                break;
            }
        }
    }

    cout << operations.size() << "\n";
    for (auto [op, param] : operations) {
        cout << op << " " << param << "\n";
    }

    return 0;
}

