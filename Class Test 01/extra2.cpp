/// Find the Shortest Subarray with Sum at Least K
#include <bits/stdc++.h>
using namespace std;

int shortestSubarrayWithSumAtLeastK(int arr[], int n, int k) {
    int minLength = INT_MAX;
    int currentSum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        currentSum += arr[right];

        while (currentSum >= k) {
            minLength = min(minLength, right - left + 1);
            currentSum -= arr[left];
            left++;
        }
    }

    return minLength == INT_MAX ? -1 : minLength;
}

int main() {
    // Example 1
    int nums1[] = {2, -1, 2};
    int k1 = 3;
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    cout << "Shortest subarray length with sum at least " << k1 << ": " << shortestSubarrayWithSumAtLeastK(nums1, n1, k1) << endl;

    // Example 2
    int nums2[] = {1, 2, 3, 4, 5};
    int k2 = 11;
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    cout << "Shortest subarray length with sum at least " << k2 << ": " << shortestSubarrayWithSumAtLeastK(nums2, n2, k2) << endl;

    // Example 3
    int nums3[] = {1, 2};
    int k3 = 4;
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    cout << "Shortest subarray length with sum at least " << k3 << ": " << shortestSubarrayWithSumAtLeastK(nums3, n3, k3) << endl;

    return 0;
}

