#include<stdio.h>
#include<stdbool.h>

bool Search(int arr[], int n, int key, bool isSorted)
{
    if (isSorted) {
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
                return true;
            else if (arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (arr[i] == key)
                return true;
        }
    }

    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int key;
    scanf("%d", &key);

    int isSorted;
    scanf("%d", &isSorted);

    bool answer = Search(arr, n, key, isSorted == 0 ? false : true);

    if (answer)
        printf("Found.\n");
    else
        printf("Not Found.\n");

    return 0;
}

