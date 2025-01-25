#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int m = (left+right)/2;
    int mid = nums[m];
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

    int i=0;
    while(i < n) {
        cin >> nums[i];
        i++;
    }
    quickSort(nums, 0, n - 1);

    int j=0;
    while(j < n) {
        cout << nums[j] << " ";
        j++;
    }
    return 0;
}

