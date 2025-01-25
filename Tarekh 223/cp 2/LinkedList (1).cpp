#include<iostream>
#include<random>
// #include<time.h>
using namespace std;

struct ListNode
{
    int value;
    ListNode* next;
};


ListNode* head = NULL;
ListNode* tail = NULL;

ListNode* createListNode(int data)
{
    ListNode* test = new ListNode();
    test->value = data;
    test->next = NULL;
    return test;
}


ListNode* Search(int data)
{
    for(ListNode* i = head; i!=NULL; i=i->next)
    {
        if(i->value==data)
            return i;
    }
    return NULL;
}

void InsertLast(int value)
{
    if(head==NULL)
    {
        head = createListNode(value);
        tail = head;
    }
    else
    {
        ListNode* temp = createListNode(value);
        tail->next = temp;
        tail = temp;
        temp = NULL;
    }
}


void InsertFirst(int data)
{
    ListNode* temp = createListNode(data);
    temp->next = head;
    head = temp;
}


void InsertMiddle(int data, int insertAfer)
{
    ListNode* location = Search(insertAfer);
    ListNode* temp = createListNode(data);

    temp->next = location->next;
    location->next = temp;
}

void printList()
{
    for(ListNode* i=head; i!=NULL; i=i->next)
    {
        cout << i->value << " ";
    }
    cout << endl;
}

void DeleteFirst()
{
    ListNode* temp = head;
    head = head->next;
    temp->next = NULL;
    delete(temp);
}

void DeleteLast()
{
    ListNode* prevLast = head;
    while(prevLast->next->next!=NULL)
    {
        prevLast = prevLast->next;
    }

    prevLast->next = NULL;
    delete(tail);
    tail = prevLast;
}

void DeleteMiddle(int data)
{

}

int main()
{

    // srand(time(NULL));

    for(int i=1; i<=5; i++)
    {
        InsertLast(rand()%50);
    }
    printList();


    printf("After insert first---> \n");

    InsertFirst(1000);
    printList();

    printf("After insert middle ---> \n");
    InsertMiddle(64, 34);
    printList();


    DeleteFirst();
    printf("After deleting first element ---> \n");
    printList();


    DeleteLast();
    printf("After deleting last element ---> \n");
    printList();

    return 0;
}

