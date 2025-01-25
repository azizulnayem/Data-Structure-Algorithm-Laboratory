#include <stdio.h>
#define DELETED -99999
#define FAILED -99999
#define SUCCESS 99999
int *stack;
int top = -1;
int stack_size=-1;

void createStack(int size){
    stack_size=size;
    stack=(int*)malloc(size*sizeof(int));
}

int isStackEmpty() {

   return (top == -1);

}

int isStackFull() {

   return (top== stack_size-1);
}

int peek() {

   if(!isStackEmpty()) {
      return stack[top];
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
      return FAILED;
   }
}

int pop() {
   int data;

   if(!isStackEmpty()) {
      data = stack[top];
      stack[top]=DELETED;
      top = top - 1;
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
      return FAILED;
   }
}

int push(int data) {

   if(!isStackFull()) {
      top = top + 1;
      stack[top] = data;
      printf("\nPushed %d in the stack. ", data);

   } else {
      printf("\nCould not insert data, Stack is full. ");
      return FAILED;
   }
}

void printStack(){
    if(isStackEmpty()){
        printf("\nStack is Empty ");
    }
    else{
        int i;
        printf("\nStack elements are:  (top)");
        for(i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
    }
}

int getStackCount(){
    return top+1;
}

int getStackCapacity(){
    return stack_size;
}

