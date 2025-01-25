#include<stdio.h>
#include "stack.c"
#define MAX 100
#define LARGE_NEGATIVE -99999
int main(){
    createStack(10);
    while(1){
        printf("1.pop item  2.print\n");
        int choice,i;
        scanf("%d",&choice);
        if(choice==1){
            int res=pop();
            if(res!=FAILED){
               for(int i=1; i<=MAX; i++){
                if(res%2!=0){
                    printf("popped %d\n", res);
                }
               }

            }

        }
        else if(choice==2)
        {
            printStack();
        }
    }
    return 0;
}
