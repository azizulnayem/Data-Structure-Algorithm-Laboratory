#include<stdio.h>
#include "stack.c"
#define LARGE_NEGATIVE -99999

int findMax(){

    int max=LARGE_NEGATIVE;
    while(!isStackEmpty()){
        int curr=pop();
        if(curr>max){
            max=curr;
        }
    }

    return max;

}

int findSecondMax(){

    int max1=LARGE_NEGATIVE;
    int max2=LARGE_NEGATIVE;
    while(!isStackEmpty()){
        int curr=pop();
        if(curr>max1){
            max2=max1;
            max1=curr;
        }
        else if(curr>max2 && curr<max1){
            max2=curr;
        }
    }

    return max2;

}


int main() {
   // push items on to the stack
   createStack(10);

   while(1)
    {
        printf("\n\n*******************************************************************\n");
        printf("1. Push item. 2. Pop item. 3. Peek item. 4.Is Empty?.  \n");
        printf("5. Is Full?. 6. Get Count. 7. get Capacity 8.Print  9.exit. 10. Find Max  11. Find second Max\n");

        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("give an item to push: ");
            int item;
            scanf("%d", &item);
            push(item);
        }
        else if(choice==2)
        {
            int res=pop();
            if(res!=FAILED)
                printf("popped %d\n", res);
        }
         else if(choice==3)
        {
            int res=peek();
            if(res!=FAILED)
                printf("peeked %d\n", res);
        }
          else if(choice==4)
        {
            int res=isStackEmpty();
            if(res)
                printf(" Yes\n");
            else
                printf("No\n");
        }
        else if(choice==5)
        {
            int res=isStackFull();
            if(res)
                printf(" Yes\n");
            else
                printf("No\n");
        }
         else if(choice==6)
        {
            printf("Number of elements in Stack: %d\n", getStackCount());
        }
         else if(choice==7)
        {
            printf("Stack Capacity: %d\n", getStackCapacity());
        }
        else if(choice==8)
        {
            printStack();
        }
        else if(choice==9)
        {
            break;
        }
        else if(choice==10)
        {
            printf("\nThe max element is: %d", findMax());
        }
        else if(choice==11)
        {
            printf("\nThe second max element is: %d", findSecondMax());
        }
    }

   return 0;
}

