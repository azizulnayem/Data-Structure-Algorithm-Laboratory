#include<stdio.h>
int leftSide(int arr[], int n, int key)
{
    int low = 0;
    int high = n-1;
    int answer;

    while(low<=high)
    {
        int mid = (low+high)>>1;
        if(arr[mid]>=key)
        {
            answer = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return answer;
}


int rightSide(int arr[], int n, int key)
{
    int low = 0;
    int high = n-1;
    int answer;

    while(low<=high)
    {
        int mid = (low+high)>>1;
        if(arr[mid]<=key)
        {
            answer = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return answer;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    int key;
    scanf("%d", &key);

    int leftSideIndex = leftSide(arr, n, key);
    int rightSideIndex = rightSide(arr, n, key);

    printf("Freq of %d: %d\n", key, rightSideIndex-leftSideIndex+1);
    return 0;
}
