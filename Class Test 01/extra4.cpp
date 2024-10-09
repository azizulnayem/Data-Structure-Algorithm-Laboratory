///Longest Subarray with Sum Equal to K
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(int arr[], int n, int k) {
    unordered_map<int, int> cumSumIndex;
    int cumSum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        cumSum += arr[i];

        if (cumSum == k) {
            maxLength = i + 1;
        }

        if (cumSumIndex.find(cumSum - k) != cumSumIndex.end()) {
            maxLength = max(maxLength, i - cumSumIndex[cumSum - k]);
        }

        if (cumSumIndex.find(cumSum) == cumSumIndex.end()) {
            cumSumIndex[cumSum] = i;
        }
    }

    return maxLength;
}

int main() {
    // Example 1
    int nums1[] = {1, -1, 5, -2, 3};
    int k1 = 3;
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    cout << "Longest subarray length with sum " << k1 << ": " << longestSubarrayWithSumK(nums1, n1, k1) << endl;

    // Example 2
    int nums2[] = {-2, -1, 2, 1};
    int k2 = 1;
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    cout << "Longest subarray length with sum " << k2 << ": " << longestSubarrayWithSumK(nums2, n2, k2) << endl;

    // Example 3
    int nums3[] = {1, 2, 3};
    int k3 = 3;
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    cout << "Longest subarray length with sum " << k3 << ": " << longestSubarrayWithSumK(nums3, n3, k3) << endl;

    return 0;
}

