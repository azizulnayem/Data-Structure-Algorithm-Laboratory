#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i=i+1)
    {
        scanf("%d", &arr[i]);
    }

    /// reverse the array
    for(int i=0, j=n-1; i<j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }


    for(int i=0; i<n; i=i+1)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

