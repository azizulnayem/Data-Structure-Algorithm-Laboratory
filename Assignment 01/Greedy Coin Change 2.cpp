#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makeChange(int amount, vector<int>& denominations) {
    sort(denominations.rbegin(), denominations.rend());

    vector<int> coinCounts(denominations.size(), 0);

    for (size_t i = 0; i < denominations.size(); ++i) {
        coinCounts[i] = amount / denominations[i];
        amount %= denominations[i];
    }

    for (size_t i = 0; i < denominations.size(); ++i) {
        if (coinCounts[i] > 0) {
            cout << denominations[i] << " cents --- " << coinCounts[i] << endl;
        }
    }

    int totalCoins = 0;
    for (size_t i = 0; i < coinCounts.size(); ++i) {
        totalCoins += coinCounts[i];
    }

    cout << "Total " << totalCoins << " coins" << endl;
}

int main() {
    int amount;
    cout << "Enter the amount in cents: ";
    cin >> amount;

    if (amount < 0) {
        cout << "Invalid input. Amount must be a non-negative integer." << endl;
        return 1;
    }

    int numDenominations;
    cout << "Enter the number of coin denominations: ";
    cin >> numDenominations;

    vector<int> denominations(numDenominations);

    cout << "Enter the coin denominations:" << endl;
    for (int i = 0; i < numDenominations; ++i) {
        cin >> denominations[i];
    }

    makeChange(amount, denominations);

    return 0;
}

