#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
/// Insert node at the front ///
void insertFront(struct node **head, int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=(*head);
    newNode->prev=NULL;
    if((*head)!=NULL){
        (*head)->newNode;
    }
    (*head)=newNode;
}
/// print function ///
void displayList(struct node *nodes){
    struct node*last;
    while(nodes!=NULL){
        printf("%d->",nodes->data);
        last=nodes;
        nodes=nodes->next;
    }
    if(nodes==NULL){
        printf("NULL\n");
    }
}
int main(){
    struct node*head=NULL;
    insertFront(&head,5);
    displayList(head);
}
