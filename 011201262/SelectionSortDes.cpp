#include<stdio.h>

void printArray(int arr[], int n)
{
    printf("The elements of the array: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int maxFinder(int arr[], int first, int last)
{
    int maximumIndex = first;
    for(int i=first+1; i<=last; i++)
    {
        if(arr[i]>arr[maximumIndex])
        {
            maximumIndex = i;
        }
    }
    return maximumIndex;
}

void selectionSort(int arr[], int n)
{
    for(int currentPosition=0; currentPosition<n-1; currentPosition++)
    {
        int maxIndex = maxFinder(arr, currentPosition, n-1);

        int temp = arr[currentPosition];
        arr[currentPosition] = arr[maxIndex];
        arr[maxIndex] = temp;

        /// printArray(arr,n);
    }
}


int main()
{
    int arr[7] = {3, 5, 4, 2, 1, 8, 7};
    int n = 7;
    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
