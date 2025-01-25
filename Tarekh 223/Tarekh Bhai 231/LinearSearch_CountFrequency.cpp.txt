#include<stdio.h>
int linearSearch(int arr[], int n, int key)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==key) return i;
    }
    return -1;
}

int linearSearchElementCount(int arr[], int n, int key)
{
    int counter = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==key)
            counter++;
    }
    return counter;
}

void printPositionsOfElement(int arr[], int n, int key)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==key)
            printf("%d ", i);
    }
    printf("\n");
}

void linearSearchCountFreq(int arr[], int n, int key)
{
    if(linearSearch(arr, n, key)!=-1)
    {
        printf("Exist!\n");
        printf("Count: %d\n", linearSearchElementCount(arr, n, key));
        printf("Position: ");
        printPositionsOfElement(arr, n, key);
    }
    else
        printf("Not Exist!\n");

}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    int key; scanf("%d", &key);

    linearSearchCountFreq(arr, n, key);

    return 0;
}
