#include<stdio.h>
#include "stack.c"
#include "queue.c"



int max;


int main(){
    while(1){

        int curr=pop();
        if(curr%max!=0){
            max=curr;
            enqueue(max);

        }
}


    createStack(5);
    createQueue(5);


    printStack();
    printQueue();


}
