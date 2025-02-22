#include<stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n-1;

    while(low<=high)
    {
        int mid = (low + high)/2;
        if(arr[mid]==key) return mid;
        else if(key>arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);


    int key; scanf("%d", &key);
    int result = binarySearch(arr, n, key);

    if(result==-1)
        printf("Not Found\n");
    else
        printf("Found at index: %d\n", result);


    return 0;
}
