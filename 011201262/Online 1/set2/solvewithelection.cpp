
#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int FindKthMinimum(int arr[], int n, int K) {
    for (int i = 0; i < K; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(&arr[i], &arr[minIndex]);
    }
    return arr[K - 1];
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int K;
    scanf("%d", &K);

    int KthMinimum = FindKthMinimum(arr, n, K);
    printf("The Kth Minimum Element of the array is: %d\n", KthMinimum);

    return 0;
}
