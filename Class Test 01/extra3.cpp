///Maximum Product Subarray
#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(int arr[], int n) {
    if (n == 0) return 0;

    int maxProduct = arr[0];
    int minProduct = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            swap(maxProduct, minProduct);
        }

        maxProduct = max(arr[i], maxProduct * arr[i]);
        minProduct = min(arr[i], minProduct * arr[i]);

        result = max(result, maxProduct);
    }

    return result;
}

int main() {
    // Example 1
    int nums1[] = {2, 3, -2, 4};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    cout << "Maximum product subarray: " << maxProductSubarray(nums1, n1) << endl;

    // Example 2
    int nums2[] = {-2, 0, -1};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    cout << "Maximum product subarray: " << maxProductSubarray(nums2, n2) << endl;

    // Example 3
    int nums3[] = {0, 2};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    cout << "Maximum product subarray: " << maxProductSubarray(nums3, n3) << endl;

    return 0;
}

