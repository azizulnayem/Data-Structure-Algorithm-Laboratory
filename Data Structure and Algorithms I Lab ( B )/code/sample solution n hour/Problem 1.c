#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    int is_swap=1;

    while(is_swap)        //for (i = 0; i < n-1; i++)
    {
        // Last i elements are already in place
        is_swap=0;
        for (j = 0; j < n-1; j++){
            if (arr[j] < arr[j+1]){
                is_swap=1;
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
    int sz = 20;
    int Arr[sz],i;
    for(i=0;i<sz;i++)
        Arr[i]=rand()%500;   //Generate number between 0 to 99

	printf("unSorted array: \n");
	printArray(Arr, 20);
	bubbleSort(Arr, 20);
	printf("Sorted array: \n");
	printArray(Arr, 20);
	return 0;
}
