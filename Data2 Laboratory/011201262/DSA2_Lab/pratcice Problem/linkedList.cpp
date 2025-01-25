#include<bits/stdc++.h>
using namespace std;

struct Node {

    int data;
   struct Node * next;
};

void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref;

  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
  *head_ref = new_node;
  return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}


void displayList(struct Node *node)
{
   while (node != NULL)
   {
      cout<<node->data<<"-->";
      node = node->next;
   }

if(node== NULL)
cout<<"null";
}

void  lastNodeDelete(struct Node * node)
{
    while (node != NULL)
   {


   }


}


int main()
{
    struct Node *head = NULL;//head
    insertAtEnd(&head,10);
    insertAtEnd(&head,20);
    insertAtEnd(&head,30);
    displayList(head);

return 0;
}
