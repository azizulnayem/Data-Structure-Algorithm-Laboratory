-#include<stdio.h>
void reverseOrder(int arr[], int n)
{
    int i;
    if(n>0)
    {
        i = n-1;
        printf("%d ",arr[i]);
        reverseOrder(arr,i);
    }
return;
}
int main()
{
    int n,j;
    scanf("%d",&n);
    int arr[n];
    for(j=0;j<n;j++)
    {
        scanf("%d",&arr[j]);
    }

    reverseOrder(arr,n);
    return 0;
}

