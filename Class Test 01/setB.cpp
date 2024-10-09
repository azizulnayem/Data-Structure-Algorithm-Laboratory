#include <bits/stdc++.h>
using namespace std;

int minSubarraySum(int arr[], int left, int right) {
    if (left == right) return arr[left];

    int mid = (left + right) / 2;

    int leftMin = INT_MAX, leftSum = 0;
    for (int i = mid; i >= left; i--) {
        leftSum += arr[i];
        leftMin = min(leftMin, leftSum);
    }

    int rightMin = INT_MAX, rightSum = 0;
    for (int j = mid + 1; j <= right; j++) {
        rightSum += arr[j];
        rightMin = min(rightMin, rightSum);
    }

    int crossingMin = leftMin + rightMin;
    int minLeft = minSubarraySum(arr, left, mid);
    int minRight = minSubarraySum(arr, mid + 1, right);

    return min(crossingMin, min(minLeft, minRight));
}

int main() {
    int nums[] = {3, -1, -4, 2, -6, 1, 5};
    ///int nums[] = {1};
    ///int nums[] = {-5, -2, -1, 0, 1};

    int n = sizeof(nums) / sizeof(nums[0]);

    int minSum = minSubarraySum(nums, 0, n - 1);
    cout << "Minimum subarray sum: " << minSum << endl;

    return 0;
}
