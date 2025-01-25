#include <stdio.h>

void findRepetitiveElements(int arr[], int n) {
    int found = 0;

    // Sorting the array using insertion sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("Repeated elements in the array: ");
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1] && (i == 0 || arr[i] != arr[i - 1])) {
            printf("%d ", arr[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }

    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findRepetitiveElements(arr, n);

    return 0;
}
