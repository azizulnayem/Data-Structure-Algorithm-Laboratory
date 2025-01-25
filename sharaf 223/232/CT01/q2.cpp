#include <stdio.h>

int findMostFrequentElement(int arr[], int n) {
    int maxElement = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    int count[maxElement + 1];
    for (int i = 0; i <= maxElement; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int maxCount = 0;
    int mostFrequentElement = arr[0];
    for (int i = 0; i < n; i++) {
        if (count[arr[i]] > maxCount) {
            maxCount = count[arr[i]];
            mostFrequentElement = arr[i];
        }
    }

    return mostFrequentElement;
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int mostFrequentElement = findMostFrequentElement(arr, n);

    printf("Most frequent element: %d\n", mostFrequentElement);

    return 0;
}
