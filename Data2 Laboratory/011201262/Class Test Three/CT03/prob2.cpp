#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

bool compareItems(const Item& i1, const Item& i2) {
    return i1.weight < i2.weight;
}

void fractionalKnapsack(int knapsackSize, const std::vector<Item>& items) {
    std::vector<Item> selectedItems;

    int currentWeight = 0;
    for (const auto& item : items) {
        if (currentWeight + item.weight <= knapsackSize) {
            selectedItems.push_back(item);
            currentWeight += item.weight;
        } else {
            break;
        }
    }

    std::cout << "Items taken (Weight, Value, Portion):" << std::endl;
    for (const auto& item : selectedItems) {
        std::cout << item.weight << " " << item.value << " " << 1 << std::endl;
    }
}

int main() {
    int knapsackSize, n;
    std::cin >> knapsackSize >> n;

    std::vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        std::cin >> items[i].weight >> items[i].value;
    }

    std::sort(items.begin(), items.end(), compareItems);

    fractionalKnapsack(knapsackSize, items);

    return 0;
}
