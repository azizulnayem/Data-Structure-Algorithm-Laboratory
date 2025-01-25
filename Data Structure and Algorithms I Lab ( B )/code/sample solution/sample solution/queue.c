#include <stdio.h>
#define DELETED -99999
#define FAILED -99999
#define SUCCESS 99999

int queue_size=-1;

int *queue;
int front = 0;
int rear = -1;
int itemCount = 0;

void createQueue(int size){
    queue_size=size;
    queue=(int*)malloc(size*sizeof(int));
}

int getFront() {
    if(!isQueueEmpty())
        return queue[front];
    else {
      printf("Could not retrieve data, Queue is empty.\n");
      return FAILED;
   }
}

int getRear() {
    if(!isQueueEmpty())
        return queue[rear];
    else {
      printf("Could not retrieve data, Queue is empty.\n");
      return FAILED;
   }
}


int isQueueEmpty() {
   return itemCount == 0;
}

int isQueueFull() {
   return itemCount == queue_size;
}

int enqueue(int data) {

   if(!isQueueFull()) {

      if(rear == queue_size-1) {
         rear = -1;
      }

      queue[++rear] = data;
      itemCount++;
      printf("\nInserted %d in the queue.", data);
   }
    else {
      printf("\nCould not insert data, Queue is full.");
      return FAILED;
   }
}

int dequeue() {
    if(!isQueueEmpty()){
         int data = queue[front++];

        if(front == queue_size) {
          front = 0;
        }

        itemCount--;
        return data;
    }
    else {
      printf("Could not dequeue data, Queue is empty.\n");
      return FAILED;
   }


}

int getQueueItemCout(){
    return itemCount;
}

int getQueueCapacity(){
    return queue_size;
}

void printQueue(){
    if(isQueueEmpty()){
        printf("Queue is Empty\n");
    }
    else{
        int i;
        printf("\nQueue elements are:  (rear)");
        for(i=rear;i>=front;i--){
            printf("%d ",queue[i]);
        }
        printf(" (front)");
    }
}

