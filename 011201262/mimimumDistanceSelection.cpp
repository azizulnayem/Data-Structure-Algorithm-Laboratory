#include<stdio.h>
#include<climits>
#include<math.h>

struct Result
{
    int distance;
    int firstIndex;
    int secondIndex;
};

Result minimumDistance(int arr[], int n)
{
    // Sorting the array using selection sort
    for(int i=0; i<n-1; i++)
    {
        int minIndex = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

    int minDistance = INT_MAX;
    int firstIndex;
    int secondIndex;

    for(int i=0; i<n-1; i++)
    {
        int distance = abs(arr[i] - arr[i+1]);
        if(distance < minDistance)
        {
            minDistance = distance;
            firstIndex = i;
            secondIndex = i+1;
        }
    }

    return {minDistance, firstIndex, secondIndex};
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    Result result = minimumDistance(arr, n);
    printf("Distance: %d\nIndices: %d %d\n", result.distance, result.firstIndex, result.secondIndex);
    return 0;
}
