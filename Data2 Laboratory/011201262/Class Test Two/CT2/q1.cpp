#include <stdio.h>

int findRotations(int arr[], int low, int high) {

    if (high < low)
        return 0;


    if (high == low)
        return low;

    int mid = low + (high - low) / 2;

    if (mid < high && arr[mid] > arr[mid + 1])
        return mid + 1;


    if (mid > low && arr[mid] < arr[mid - 1])
        return mid;

    if (arr[high] > arr[mid])
        return findRotations(arr, low, mid - 1);
    else
        return findRotations(arr, mid + 1, high);
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int rotations = findRotations(arr, 0, n - 1);
    printf("%d\n", rotations);

    return 0;
}
