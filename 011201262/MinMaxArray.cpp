#include<stdio.h>
struct MinMax
{
    int minimum;
    int maximum;
};

typedef struct MinMax MinMax;

MinMax arrayMinimumMaximum(int arr[], int n)
{
    int minimum = arr[0];
    int maximum = arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]<minimum) minimum = arr[i];

        if(arr[i]>maximum) maximum = arr[i];
    }

    MinMax result;
    result.minimum = minimum;
    result.maximum = maximum;
    return result;
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

    MinMax result = arrayMinimumMaximum(arr, n);
    printf("Minimum: %d Maximum: %d\n", result.minimum, result.maximum);

    return 0;
}
