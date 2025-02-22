#include<stdio.h>

int findMinIndex(int arr[], int n)
{
    int minimum = arr[0];
    int minIndex = 0;
    for(int i=1;i<n; i++)
    {
        if(arr[i]<minimum)
        {
            minimum = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int index = findMinIndex(arr, n);
    printf("Minimum Index: %d\n", index);
    return 0;
}
