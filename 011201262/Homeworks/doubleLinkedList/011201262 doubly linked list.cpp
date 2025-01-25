#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int value;
    struct ListNode* next;
    struct ListNode* prev;
};
typedef struct ListNode ListNode;

ListNode* head = NULL;
ListNode* tail = NULL;

ListNode* createListNode(int data)
{
    ListNode* temp;
    temp = (ListNode *)malloc(sizeof(ListNode));
    temp->value = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

ListNode* linearSearch(int key)
{
    ListNode* i = head;
    while(i!=NULL)
    {
        if(i->value==key)
        {
            return i;
        }
        i=i->next;
    }
    return NULL;
}

void insertFirstElement(int data)
{
    head = createListNode(data);
    tail = head;
}

void insertLast(int data)
{
    if(head==NULL)
    {
        insertFirstElement(data);
    }
    else
    {
        ListNode* temp = createListNode(data);
        temp->prev = tail;
        tail->next = temp;
        tail = tail->next; /// tail = temp;
    }
}

void insertFirst(int data)
{
    if(head==NULL)
    {
        insertFirstElement(data);
    }
    else
    {
        ListNode* temp = createListNode(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAfter(int data, int key)
{
    ListNode* location = linearSearch(key);
    if(location==NULL)
        return;

    ListNode* temp = createListNode(data);
    temp->next = location->next;
    temp->prev = location;
    if(location->next!=NULL)
        location->next->prev= temp;
    location->next = temp;
    if(location==tail)
        tail = tail->next;
}

void printList()
{
    /**
    /// for printing the elements of an array
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }**/

    /** for(ListNode* i=head; i!=NULL; i=i->next)
    {
        printf("%d ", i->value);
    }**/
    printf("The elements of the Linked List: ");
    ListNode* i = head;
    while(i!=NULL)
    {
        printf("%d ", i->value);
        i=i->next;
    }
    printf("\n");
}

void deleteFirst()
{
    if(head==NULL)
        return;
    else if(head==tail)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        ListNode* temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void deleteLast()
{
    if(tail==NULL)
        return;
    else if(head==tail)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        /**ListNode* i = head;
        while(i->next!=tail)
        {
            i = i->next;
        }
        i->next = NULL;
        free(tail);
        tail = i;**/
        ListNode* i = tail;
        tail = tail->prev;
        tail->next= NULL;
        free(i);
    }
}

void deleteKey(int key)
{
    if(head==NULL)
        return;
    else if(head==tail)
    {
        if(head->value==key)
            deleteFirst();
    }
    else
    {
        if(head->value==key)
            deleteFirst();
        else
        {
            ///ListNode* prevLocation = NULL;
            ListNode* i = head;
            while(i!=NULL && i->value!=key)
            {
                ///prevLocation = i;
                i = i->next;
            }
            if(i==NULL)
                return;
            else {
                if(i==tail)
                    tail = i->prev;
                i->prev->next = i->next;
                if(i->next!= NULL)
                    i->next->prev = i->prev;
                free(i);
            }
        }
    }
}

int main()
{
    insertLast(10);
    insertLast(15);
    insertLast(20);
    insertLast(30);
    insertLast(45);
    insertLast(75);
    insertLast(90);

    printList();

    insertFirst(100);
    insertFirst(110);

    printList();

    insertAfter(25, 20);
    insertAfter(35, 25);
    printList();

    deleteFirst();
    printList();

    deleteLast();
    deleteLast();
    printList();

    deleteKey(100);
    printList();

    deleteKey(45);
    printList();

    deleteKey(35);
    printList();


    /**
    ListNode* searchResult = linearSearch(27);
    if(searchResult==NULL)
        printf("Not Found\n");
    else
        printf("Found at %d\n", searchResult);
    **/

    /***
    printf("Head address: %d\n", head);
    printf("Head next address: %d\n", head->next);


    int arr[10];
    printf("\n\nFirst element address (array): %d\n", &arr[0]);
    printf("Second element address (array): %d", &arr[1]);
    ***/



    return 0;
}
