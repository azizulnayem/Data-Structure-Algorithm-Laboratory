/*#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head;
void list(){
    head=0;
}
void insertData(int data){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=head;
    head=newNode;
}
void print(){
    struct Node *current;
    current=head;
    while(current!=0){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}
int findMax(){
    struct Node *current=head;
    int max=head->data;
    if(head==NULL){
        printf("Empty List\n");
    }
    else{
        do{
            if(max<current->data){
                max=current->data;
            }
            current=current->next;
        }while(current!=head);
        printf("Maximum: %d",max);
    }
}
int main(){
    list();
    while(1){
        printf("\n----------------------------------------------------- \n");
        printf("1.Insert Data  2.List \n3.Find Maximum Element   4.Find Minimum Element\n");
        printf("-----------------------------------------------------\n");
        int input;
        scanf("%d",&input);
        if(input==1){
            printf("insert item: ");
            int insert;
            scanf("%d",&insert);
            insertData(insert);
            printf("insert successful\n");
        }
        else if(input==2){
            printf("List: ");
            print();
        }
        else if(input==3){
            findMax();
        }
        else if(input==4){

        }
    }
}*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;


void add(int data){

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if(head == NULL){
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }else {

        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void minNode() {
    struct node *current = head;

    int min = head->data;
    if(head == NULL) {
        printf("\nList is empty");
    }
    else {
         do{

             if(min > current->data) {
                 min = current->data;
             }
             current= current->next;
        }while(current != head);

        printf("Minimum value node in the list: %d", min);
    }
}


void maxNode() {
    struct node *current = head;
    int max = head->data;
    if(head == NULL) {
        printf("\nList is empty");
    }
    else {
         do{
             if(max < current->data) {
                 max = current->data;
             }
             current= current->next;
            }while(current != head);

        printf("\nMaximum value node in the list: %d\n", max);
    }
}

int main()
{

    add(5);
    add(20);
    add(10);
    add(45);
    add(90);
    minNode();

    maxNode();

   return 0;
}

