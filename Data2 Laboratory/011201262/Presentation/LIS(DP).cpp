#include <iostream>
#include <vector>
using namespace std;

int longest_increasing_subsequence(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        int max_length = 0;
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                max_length = max(max_length, dp[j]);
            }
        }
        dp[i] = max_length + 1;
    }

    int max_length = 0;
    for (int i = 0; i < n; ++i) {
        max_length = max(max_length, dp[i]);
    }

    return max_length;
}

int main() {
    vector<int> arr = {11, 23, 10, 32, 20, 49, 42, 61};
    int lis_length = longest_increasing_subsequence(arr);
    cout << "Length of the Longest Increasing Subsequence: " << lis_length << endl;
    return 0;
}
