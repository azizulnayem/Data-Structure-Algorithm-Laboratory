#include<stdio.h>

int main()
{
    int arr[100]={1,2,3,4,5,6},key=4,n=5;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==key)
        {
            printf("%d",arr[i]);
            break;
        }
        printf("occur : %d\n",i+1);
    }
}
