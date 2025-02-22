#include<iostream>
#include<stdio.h>
using namespace std;

struct ListNode
{
    int value;
    ListNode *next;
};

ListNode* head = NULL;
ListNode* tail = NULL;

ListNode* createListNode(int data)
{
    ListNode* temp = new ListNode();
    temp->value = data;
    temp->next = NULL;
    return temp;
}

ListNode* linearSearch(int key)
{
    for(ListNode* i=head;i!=NULL;i=i->next)
    {
        if(i->value==key)
            return i;
    }
    return NULL;
}

void insertFirst(int data)
{
    if(head==NULL)
    {
        ListNode* temp = createListNode(data);
        head = temp;
        tail = head;
        temp = NULL;
    }
    else
    {
        ListNode* temp = createListNode(data);
        temp->next = head;
        head = temp;
        temp = NULL;
    }
}

void insertLast(int data)
{
    if(head==NULL)
    {
        ListNode* temp = createListNode(data);
        head = temp;
        tail = head;
        temp = NULL;
    }
    else
    {
        ListNode* temp = createListNode(data);
        tail->next = temp;
        tail = tail->next;
        temp = NULL;
    }
}

void insertMiddle(int insertAfter, int data)
{
    if(head==NULL)
    {
        ListNode* temp = createListNode(data);
        head = temp;
        tail = head;
        temp = NULL;
    }
    else
    {
        ListNode* loc = linearSearch(insertAfter);
        ListNode* temp = createListNode(data);
        temp->next = loc->next;
        loc->next = temp;
        temp = NULL;
    }
}


ListNode* previousLocation(int data)
{
    ListNode* prevLoc = NULL;
    ListNode* loc = head;
    while(loc!=NULL && loc->value!=data)
    {
        prevLoc = loc;
        loc = loc->next;
    }
    if(loc==NULL)
        return NULL;
    else
        return prevLoc;
}

void printList()
{
    printf("The elements of the linked list: ");
    for(ListNode* i = head; i!=NULL; i=i->next)
    {
        printf("%d ", i->value);
    }
    printf("\n");
}

void deleteFirst()
{

}

void deleteLast()
{

}

void deleteMiddle(int data)
{

}

int main()
{
    for(int i=10;i<=100; i+=10)
        insertFirst(i);
    printList();

    deleteFirst();
    printList();

    deleteLast();
    printList();

    deleteMiddle(50);
    printList();

    deleteMiddle(75);
    printList();
    return 0;
}
