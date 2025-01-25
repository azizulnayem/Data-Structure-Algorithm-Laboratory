#include<stdio.h>

int arraySum(int arr[], int n)
{
    int summation = 0;
    for(int i=0; i<n; i++)
        summation += arr[i];
    return summation;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum = arraySum(arr, n);
    printf("Summation: %d\n", sum);
    printf("Average: %.1lf\n", (float)sum/n);

    return 0;
}
