
#include <stdio.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int Arr[], int n)
{
	int i, j, min_idx;


	for (i = 0; i < n/2; i++)
	{

		min_idx = i;
		for (j = i+1; j < n/2; j++)
		if (Arr[j] > Arr[min_idx])
			min_idx = j;
		swap(&Arr[min_idx], &Arr[i]);



	}
	for (i = n/2; i < n-1; i++)
	{

		min_idx = i;
		for (j = n/2; j < n-1; j++)
		if (Arr[j] > Arr[min_idx])
			min_idx = j;
		swap(&Arr[min_idx], &Arr[i]);



	}






}


void printArray(int Arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", Arr[i]);
	printf("\n");
}


int main()
{
	int n=10;


    int randArray[n],i;
    for(i=0; i<n; i++)
        randArray[i]=rand()%500;
    printf("Unsorted array:\n ");
    printArray(randArray, n);

    selectionSort(randArray, n);
    printf("\n");
    printf("Sorted array: \n");
    printArray(randArray, n);




    return 0;
}

