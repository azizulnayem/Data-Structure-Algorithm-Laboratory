#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
int top,stack[max];
void push(char x){
    if(top==max-1){
        printf("stack overflow");
    }
    else{
        stack[++top]=x;
    }
}
void pop(){
    printf("%c",stack[top--]);
}
main(){
    while(1){
    char str[100];
    gets(str);
    int len=strlen(str);

    int i;
    if(str[100]==1){
        break;
    }
    for(i=0; i<len; i++){
        push(str[i]);
    }
    for(i=0; i<len; i++){
        pop();
        }
        printf("\n");
    }
}
