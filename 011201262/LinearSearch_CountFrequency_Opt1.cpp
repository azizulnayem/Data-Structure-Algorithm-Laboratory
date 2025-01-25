#include<stdio.h>
void linearSearchFindIndices(int arr[], int n, int key)
{
    int indexArray[n];
    int counter = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==key)
        {
            indexArray[counter] = i;
            counter++;
        }
    }
    if(counter==0)
        printf("Not Exist\n");
    else
    {
        printf("Exist\n");
        printf("Count: %d\n", counter);
        printf("Position: ");
        for(int i=0;i<counter;i++)
            printf("%d ", indexArray[i]);
        printf("\n");
    }

}


int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    int key; scanf("%d", &key);

    linearSearchFindIndices(arr, n, key);
    return 0;
}

