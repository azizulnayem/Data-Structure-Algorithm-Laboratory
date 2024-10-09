#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

bool compare(Item i1, Item i2) {
    return i1.ratio > i2.ratio;
}

void fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    int n = items.size();
    double totalProfit = 0.0;
    int i = 0;

    while (capacity > 0 && i < n) {
        if (capacity >= items[i].weight) {
            cout << "item " << i + 1 << ": " << items[i].weight << ".0 kg " << items[i].value << ".0 taka" << endl;
            totalProfit += items[i].value;
            capacity -= items[i].weight;
        } else {
            double fraction = static_cast<double>(capacity) / items[i].weight;
            cout << "item " << i + 1 << ": " << fraction * items[i].weight << ".0 kg " << fraction * items[i].value << ".0 taka" << endl;
            totalProfit += fraction * items[i].value;
            capacity = 0;
        }
        i++;
    }

    cout << "Profit: " << totalProfit << " taka" << endl;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter the weights and values of the items:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = static_cast<double>(items[i].value) / items[i].weight;
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    fractionalKnapsack(capacity, items);

    return 0;
}
