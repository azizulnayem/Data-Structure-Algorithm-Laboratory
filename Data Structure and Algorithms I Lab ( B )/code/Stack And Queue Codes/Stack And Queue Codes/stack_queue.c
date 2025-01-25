#include<stdio.h>
#include "stack.c"
#include "queue.c"

#define LARGE_NEGATIVE -99999

int findSMax(){

    int max=LARGE_NEGATIVE;
    while(!isStackEmpty()){
        int curr=pop();
        if(curr>max){
            max=curr;
        }
    }

    return max;

}

int findQMax(){
    int max= LARGE_NEGATIVE;

    while(!isQueueEmpty()){
        int curr=dequeue();
        if(curr>max){
            max=curr;
        }
    }

    return max;
}

int main(){

    createStack(5);
    createQueue(5);

    push(4);

    push(3);

    push(11);

    push(7);

    enqueue(3);

    enqueue(9);

    enqueue(5);

    enqueue(1);

    printStack();
    printQueue();

    printf(" \n max in stack: %d", findSMax());
    printf(" \n max in queue: %d", findQMax());


}
