
#include<stdio.h>
#include "queue.c"
#define LARGE_POSITIVE 99999

int findMin(){
    int min= LARGE_POSITIVE;

    while(!isQueueEmpty()){
        int curr=dequeue();
        if(curr<min){
            min=curr;
        }
    }

    return min;
}

int main() {
   // push items on to the Queue
   createQueue(5);

   while(1)
    {
        printf("\n\n*******************************************************************\n");
        printf("1. Enqueue item. 2. Dequeue item. 3. Get Front item. 4. Get Rear Item. 5.Is Empty?.  \n");
        printf("6. Is Full?. 7. Get Count. 8. get Capacity 9.Print  10.exit. 11.Find min\n");

        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("give an item to enqueue: ");
            int item;
            scanf("%d", &item);
            enqueue(item);
        }
        else if(choice==2)
        {
            int res=dequeue();
            if(res!=FAILED)
                printf("dequeued %d\n", res);
        }
         else if(choice==3)
        {
            int res=getFront();
            if(res!=FAILED)
                printf("front is %d\n", res);
        }
          else if(choice==4)
        {
            int res=getRear();
            if(res!=FAILED)
                printf("rear is %d\n", res);
        }
          else if(choice==5)
        {
            int res=isQueueEmpty();
            if(res)
                printf(" Yes\n");
            else
                printf("No\n");
        }
        else if(choice==6)
        {
            int res=isQueueFull();
            if(res)
                printf(" Yes\n");
            else
                printf("No\n");
        }
         else if(choice==7)
        {
            printf("Number of elements in Queue: %d\n", getQueueItemCout());
        }
         else if(choice==8)
        {
            printf("Queue Capacity: %d\n", getQueueCapacity());
        }
        else if(choice==9)
        {
            printQueue();
        }
        else if(choice==10)
        {
            break;
        }

         else if(choice==11)
        {
            printf(" \n The min element is : %d ", findMin());
        }

    }

   return 0;
}

