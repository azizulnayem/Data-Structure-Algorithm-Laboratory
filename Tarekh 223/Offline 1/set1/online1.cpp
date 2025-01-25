#include<stdio.h>
#include<stdbool.h>

bool Search(int arr[], int n, int key, bool isSorted)
{

}

int main()
{
    int n; scanf("%d", &n);
    int arr[n];

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    int key; scanf("%d", &key);

    int isSorted; scanf("%d", &isSorted);

    bool answer = Search(arr, n, key, isSorted==0 ? false : true);

    if(answer)
        printf("Found.\n");
    else
        printf("Not Found.\n");

    return 0;
}
