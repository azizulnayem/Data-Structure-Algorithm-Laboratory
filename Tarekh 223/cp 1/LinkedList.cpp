#include<iostream>
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


void printList()
{
    for(ListNode* i=head; i!=NULL; i=i->next)
    {
        cout << i->value << " ";
    }
    cout << endl;
}

ListNode* Search(int value)
{

}

int main()
{

    for(int i=1; i<=100; i++)
    {
        InsertLast(i);
    }


    printList();

    ListNode* valueSearch = Search(5);
    if(valueSearch==NULL)
    {
        cout << "Not Found\n";
    }
    else
    {
        cout << "Found\n";
    }

    return 0;
}

