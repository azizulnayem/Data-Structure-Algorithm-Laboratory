#include <bits/stdc++.h>

using namespace std;

long long MAC(vector<int>& arr, int l, int m, int r) {
    vector<int> temp(r - l + 1);
    int i = l, j = m + 1, k = 0;
    long long count = 0;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            count += m - i + 1;
        }
    }
    while (i <= m) {
        temp[k++] = arr[i++];
    }
    while (j <= r) {
        temp[k++] = arr[j++];
    }
    for (i = l, k = 0; i <= r; ++i, ++k) {
        arr[i] = temp[k];
    }
    return count;
}

long long MSAC(vector<int>& arr, int l, int r) {
    long long count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        count += MSAC(arr, l, m);
        count += MSAC(arr, m + 1, r);
        count += MAC(arr, l, m, r);
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long long count = MSAC(arr, 0, n - 1);
    cout << count << endl;
    return 0;
}

