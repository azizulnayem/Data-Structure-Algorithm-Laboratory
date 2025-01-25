#include<stdio.h>
#include "stack.c"
#include "queue.c"

int main(){

   createStack(10);
   createQueue(10);

    push(3);
    push(7);
    push(6);
    push(4);
    push(2);
    push(1);

    printStack();

    while(!isStackEmpty()){
        int curr=pop();
        if(curr%2!=0){
            enqueue(curr);
        }
    }
    printQueue();
    printStack();

    return 0;
}
