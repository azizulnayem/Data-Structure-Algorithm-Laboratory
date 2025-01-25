
#include <stdio.h>

#include <stdlib.h>

/* A structure of linked list node */

struct node {

  int data;

  struct node *next;

} *head;

void initialize(){

    head = NULL;

}

/*

Inserts a node in front of a singly linked list.

*/

void insert(int num) {

    /* Create a new Linked List node */

    struct node* newNode = (struct node*) malloc(sizeof(struct node));

    newNode->data  = num;

    /* Next pointer of new node will point to head node of linked list  */

    newNode->next = head;

    /* make new node as the new head of linked list */

    head = newNode;

    printf("Inserted Element : %d\n", num);

}

int getLength(struct node *head){

    int length =0;

    while(head != NULL){

        head = head->next;

        length++;

    }

    return length;

}

/*

Prints a linked list from head node till the tail node

*/

void printLinkedList(struct node *nodePtr) {

  while (nodePtr != NULL) {

     printf("%d", nodePtr->data);

     nodePtr = nodePtr->next;

     if(nodePtr != NULL)

         printf("-->");

  }

}

int main() {

    initialize();

    /* Creating a linked List*/

    insert(8);

    insert(3);

    insert(2);

    insert(7);

    insert(9);

    printf("\nLinked List\n");

    printLinkedList(head);

    printf("\nLinked List Length : %d", getLength(head));

    return 0;

}
