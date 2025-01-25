#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longest_increasing_subsequence(vector<int>& arr) {
    vector<int> piles;
    for (int num : arr) {
        auto it = lower_bound(piles.begin(), piles.end(), num);
        if (it == piles.end()) {
            piles.push_back(num);
        } else {
            *it = num;
        }
    }
    return piles.size();
}

int main() {
    vector<int> arr = {11, 23, 10, 32, 20, 49, 42, 61};
    int lis_length = longest_increasing_subsequence(arr);
    cout << "Length of the Longest Increasing Subsequence: " << lis_length << endl;
    return 0;
}
