#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int left, int right) {

    if (left == right) {
        return arr[left];
    }

    int mid = (left + right) / 2;

    int leftMax = INT_MIN, leftSum = 0;

    int i = mid;
    while(i>=left){
        leftSum += arr[i];
        leftMax = max(leftMax, leftSum);
        i--;
    }

    int rightMax = INT_MIN, rightSum = 0;

    int j=mid+1;
    while(j <= right) {
        rightSum += arr[j];
        rightMax = max(rightMax, rightSum);
        j++;
    }

    int crossingMax = leftMax + rightMax;
    int maxLeft = maxSubarraySum(arr, left, mid);
    int maxRight = maxSubarraySum(arr, mid + 1, right);

    return max(crossingMax, max(maxLeft, maxRight));
}
int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    int maxSum = maxSubarraySum(nums, 0, n - 1);

    cout << "Maximum subarray sum: " << maxSum << endl;

    return 0;
}
/*int main() {
    int n;
    cin>>n;
    int nums[n];

    int i=0;
    while(i<n){
        cin>>nums[i];
        i++;
    }

    int maxSum = maxSubarraySum(nums, 0, n - 1);

    cout << "Maximum SubArray sum: " << maxSum << endl;

    return 0;
}*/

