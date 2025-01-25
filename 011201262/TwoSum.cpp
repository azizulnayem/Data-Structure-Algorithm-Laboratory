#include<stdio.h>
#include<stdbool.h>

bool twoSumPossible(int arr[], int n, int key)
{
    for(int i=0; i<n; i++)
    {
        /// int need = key - arr[i];

        for(int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j] == key)
                return true;
        }
    }
    return false;
}

int twoSumCounter(int arr[], int n, int key)
{
    int counter = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j] == key)
            {
                /// printf("%d %d\n", i , j);
                counter++;
            }
        }
    }
    return counter;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int key;
    scanf("%d", &key);

    int result = twoSumCounter(arr, n, key);

    printf("%d\n", result);
    return 0;
}
