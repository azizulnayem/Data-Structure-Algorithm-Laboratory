#include <stdio.h>

void sortArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void rearrangeArray(int arr[], int n) {
    int even[n], odd[n];
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even[evenCount] = arr[i];
            evenCount++;
        } else {
            odd[oddCount] = arr[i];
            oddCount++;
        }
    }
    sortArray(even, evenCount);
    sortArray(odd, oddCount);
    for (int i = 0; i < oddCount / 2; i++) {
        int temp = odd[i];
        odd[i] = odd[oddCount - i - 1];
        odd[oddCount - i - 1] = temp;
    }
    int index = 0;
    for (int i = 0; i < evenCount; i++) {
        arr[index] = even[i];
        index++;
    }
    for (int i = 0; i < oddCount; i++) {
        arr[index] = odd[i];
        index++;
    }
}

int main() {
    int arr,n
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrangeArray(arr, n);

    printf("Rearranged and sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
