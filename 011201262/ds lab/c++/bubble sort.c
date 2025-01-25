#include<stdio.h>

int main()
{
    int array[]={12,2,-5,5,3,-3,4,-4,10};

    int i,j,size=9;
    for(i=0; i< size-1; i++)
    {
        for(j=0; j<size-1-i; j++)
        {
            if(array[j]> array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];    //swap two numbers
                array[j+1]= temp;
            }
        }
    }
    printf("after sorting: \n");

    for(i=0; i< size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
    return 0;
}
