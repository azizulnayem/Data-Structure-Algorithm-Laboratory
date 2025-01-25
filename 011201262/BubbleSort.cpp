#include<stdio.h>
void printArray(int arr[], int n)
{
    printf("The elements of the array: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    for(int boundaryLine=n-2; boundaryLine>=0; boundaryLine--)
    {
        for(int i=0; i<=boundaryLine; i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}


int main()
{
    int arr[7] = {3, 5, 4, 2, 1, 8, 7};
    int n = 7;
    printArray(arr, n);
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}
