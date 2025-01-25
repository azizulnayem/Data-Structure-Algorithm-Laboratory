#include <bits/stdc++.h>
using namespace std;
void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = nums[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (nums[i] > mid) {
            i++;
        }
        while (nums[j] < mid) {
            j--;
        }
        if (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    quickSort(nums, left, j);
    quickSort(nums, i, right);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    quickSort(nums, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}

