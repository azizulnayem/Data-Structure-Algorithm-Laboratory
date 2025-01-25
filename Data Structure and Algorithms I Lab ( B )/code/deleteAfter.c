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
Given a Inserts a node in front of a singly linked list.
*/
void insert(int num) {
    /* Create a new Linked List node */
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    /* Next pointer of new node will point to head node of linked list  */
    newNode->next = head;
    /* make new node as new head of linked list */
    head = newNode;
    printf("Inserted Element : %d\n", num);
}

void deleteNode(struct node *head, int num) {
    struct node *current = head, *previous;
    /* Input Validation */
    if (head == NULL) {
       printf("Error : Invalid node pointer !!!\n");
       return;
    }

    /* If head head node itself contains num,
    then delete head node and shift head pointer */
    if (current->data == num) {
        head = current->next;
        free(current);
        return;
    }

    /* Traverse given linked list and search for key.
    If found, keep a pointer to previous node also. */
    while (current != NULL && current->data != num) {
        previous = current;
        current = current->next;
    }

    /* num not found in given Linked list */
    if (current == NULL){
        printf("%d not found in Linked List\n");
        return;
    }
    /* Set next pointer of previous node to
    next pointer of temp(current node)*/
    previous->next = current->next;

    /* DeAllocate memory of node */
    free(current);
}

/*
Prints a linked list from head node till tail node
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
    insert(2);
    insert(4);
    insert(5);
    insert(9);
    printf("\nBefore Deletion\n");
    printLinkedList(head);
    /* Deleting a node from Linked List */
    deleteNode(head, 5);
    /* Deleting head node */
    deleteNode(head, 2);
    printf("\nAfter Deletion\n");
    printLinkedList(head);
    return 0;
}
