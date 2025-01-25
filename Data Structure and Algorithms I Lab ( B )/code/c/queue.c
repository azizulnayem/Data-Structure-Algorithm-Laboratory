#include<stdio.h>
#include<stdlib.h>
#define size 5
int items[size], front=-1, rear=-1;
void enqueue(int value)
{
    if (rear==size-1)
        printf("queue is full");
    else {
            if(front==-1)
                front=0;
            rear++;
            items[rear]=value;
            printf("inserted - %d\n",value);
        }
}
void display() {
  if (rear == -1)
    printf("\nQueue is Empty!!!");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}
int main(){
    enqueue(22);
    enqueue(55);
    enqueue(99);

    display();
}
