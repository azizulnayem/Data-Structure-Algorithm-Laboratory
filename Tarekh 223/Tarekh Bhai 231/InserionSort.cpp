#include<stdio.h>
void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void InsertionSort(int arr[], int n)
{

}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("Before Applying Bubble Sort...... ");
    printArray(arr, n);

    InsertionSort(arr, n);

    printf("After Applying Bubble Sort...... ");
    printArray(arr, n);
    return 0;
}
