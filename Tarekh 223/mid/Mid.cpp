/**

Student ID:

**/

#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode* prev;
};

ListNode* head = NULL;
ListNode* tail = NULL;

ListNode* createListNode(int data)
{
    ListNode* temp = new ListNode();
    temp->val = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

ListNode* ForwardSearch(int data)
{
    for(ListNode* i=head; i!=NULL; i=i->next)
    {
        if(data==i->val) return i;
    }
    return NULL;
}

ListNode* BackwardSearch(int data)
{
    for(ListNode* i=tail; i!=NULL; i=i->prev)
    {
        if(data==i->val) return i;
    }
    return NULL;
}

void printList()
{
    for(ListNode* i=head; i!=NULL; i=i->next)
    {
        cout << i->val << " ";
    }
    cout << endl;
}

void printReverseList()
{
    for(ListNode* i=tail; i!=NULL; i=i->prev)
    {
        cout << i->val << " ";
    }
    cout << endl;
}

void InsertLast(int data)
{
    if(head==NULL)
    {
        head = createListNode(data);
        tail = head;
    }
    else
    {
        ListNode* temp = createListNode(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void InsertFirst(int data)
{
    if(head==NULL)
    {
        head = createListNode(data);
        tail = head;
    }
    else
    {
        ListNode* temp = createListNode(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}


void InsertMiddle(int data, int insertAfter)
{
    ListNode* location = ForwardSearch(insertAfter);
    if(location!=NULL)
    {
        ListNode* temp = createListNode(data);
        temp->next = location->next;
        location->next->prev = temp;
        location->next = temp;
        temp->prev = location;
    }
}


void deleteFirst()
{
    if(head==NULL) return;

    ListNode* temp = head;
    head = head->next;
    if(head) head->prev = NULL;
    temp->next = NULL;
    delete(temp);

    if(!head) tail = NULL;
}

void deleteLast()
{
    if(head==NULL) return;

    ListNode* temp = tail;
    tail = tail->prev;
    if(tail) tail->next = NULL;
    temp->prev = NULL;
    delete(temp);

    if(!tail) head = NULL;

}

void deleteMiddle(int data)
{
    if(head==NULL) return;

    ListNode* location = ForwardSearch(data);
    if(location)
    {
        if(location->next && location->prev)
        {
            location->prev->next = location->next;
            location->next->prev = location->prev;
            location->prev = NULL;
            location->next = NULL;
            delete(location);
        }
        else if(location->next) deleteFirst();
        else deleteLast();
    }
}


int sumOfOddElements()
{

}

void reverseList()
{

}

bool isSorted()
{

}


int main()
{

}

