#include<stdio.h>
int FindKthMinimum(int arr[], int n, int K)
{
    
}

int main()
{
    int n; scanf("%d", &n);
    int arr[n];

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    int K; scanf("%d",&K);

    int KthMinimum = FindKthMinimum(arr, n, K);
    printf("The Kth Minimum Element of the array is: %d\n", KthMinimum);

    return 0;
}
