///Count the Number of Subarrays with Sum Equal to K
#include <bits/stdc++.h>
using namespace std;

int countSubarraysWithSumK(int arr[], int n, int k) {
    unordered_map<int, int> cumSumCount;
    cumSumCount[0] = 1;
    int cumSum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        cumSum += arr[i];

        if (cumSumCount.find(cumSum - k) != cumSumCount.end()) {
            count += cumSumCount[cumSum - k];
        }

        cumSumCount[cumSum]++;
    }

    return count;
}

int main() {
    int nums1[] = {1, 1, 1};
    int k1 = 2;
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    cout << "Number of subarrays with sum " << k1 << ": " << countSubarraysWithSumK(nums1, n1, k1) << endl;

    int nums2[] = {1, 2, 3};
    int k2 = 3;
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    cout << "Number of subarrays with sum " << k2 << ": " << countSubarraysWithSumK(nums2, n2, k2) << endl;

    int nums3[] = {1, 2, 1, 2, 1};
    int k3 = 3;
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    cout << "Number of subarrays with sum " << k3 << ": " << countSubarraysWithSumK(nums3, n3, k3) << endl;

    return 0;
}

