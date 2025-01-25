#include<stdio.h>
#define SIZE 10000

struct Result
{
    int numberOfMatches;
    int indices[SIZE];
};

void linearSearch(int arr[], int n, int key)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==key)
            printf("%d ", i);
    }
    printf("\n");
}

Result linearSearchFunctional(int arr[], int n,  int key)
{
    Result result;
    result.numberOfMatches = 0;

    for(int i=0; i<n; i++)
    {
        if(arr[i]==key)
        {
            result.indices[result.numberOfMatches] = i;
            result.numberOfMatches++;
        }
    }
    return result;
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
    Result result = linearSearchFunctional(arr, n, key);
    for(int i=0; i<result.numberOfMatches; i++)
    {
        printf("%d ", result.indices[i]);
    }
    return  0;
}
