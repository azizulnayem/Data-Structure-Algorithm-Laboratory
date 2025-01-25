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
    int minDistance = INT_MAX;
    int firstIndex;
    int secondIndex;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int distance = abs(arr[i]-arr[j]);
            if(distance<minDistance)
            {
                minDistance = distance;
                firstIndex = i;
                secondIndex = j;
            }
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
