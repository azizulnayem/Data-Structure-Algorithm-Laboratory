//17.07.21 DSA-Lab
#include<stdio.h>
#include<stdlib.h>
//create new node
//point new node .next to the previous
//update head pointer
struct listNode{
    int item;
    struct listNode*next;
};
struct listNode*list;
void initializeList(){
    list=0;
}
void insertItem(int item){
    struct listNode*newNode;
    newNode=(struct listNode*)malloc(sizeof(struct listNode));
    newNode->item=item;
    newNode->next=list;
    list=newNode;
}
/*insert last
  -create new node
  -find the last element
  -replace null with new node*/
/*insert before
-create new node
-find the given old node and also its previous node
-point previous node.next to new node and point new node.next to old node
*/
int deleteItem(int item){
    struct listNode*curr,*prev;
    curr=list;
    while (curr!=0){
       if(curr->item==item)
    }
    
}
/* find deletable node and also the previous node of the deletable node
 -point previous node.next to deletable node.next 
 -update head to head next
*/