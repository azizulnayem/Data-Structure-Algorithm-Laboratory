#include<stdio.h>
struct Result
{
    int summation;
    double average;
};

typedef struct Result Result;

Result arraySummationAvg(int arr[], int n)
{
    int summation = 0;
    for(int i=0; i<n; i++)
        summation += arr[i];

    Result res;
    res.summation = summation;
    res.average = (double)summation/n;
    return res;
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

    Result sumAvg = arraySummationAvg(arr, n);

    printf("Summation: %d\n", sumAvg.summation);
    printf("Average: %.1lf\n", sumAvg.average);
    return 0;
}
