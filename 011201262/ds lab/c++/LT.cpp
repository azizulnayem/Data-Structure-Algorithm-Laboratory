#include <stdio.h>
#include <stdlib.h>
 struct Node// creating structure
{
    int data;          // data type
    struct Node *next; // structure pointer type
};
typedef struct Node node; // initializing structure as node
// declaring methods
int menu();
node *createNode(int value);
void printList(struct Node *temp);
bool valueExits(node *head, int x);
node *insert_head(struct Node *head, struct Node *nn);
node *insert_nth(struct Node *head, struct Node *nn, int n);
int list_size(struct Node *temp);
node *insert_tail(struct Node *head, struct Node *nn);
node *delete_head(node *head);
node *delete_tail(node *head);
node *delete_nth(node *head, int n);
node *insert_delete_randomly(node *head, int n);
node *deleteNode(node *head, int value);

int main()
{
    node *head = NULL, *temp, *nn;
    int ch, pos;

    ch = menu();
    while (ch != 0)
    {
        if (ch == 1)
        {
            int value;
            printf("enter value: ");
            scanf("%d", &value);
            nn = createNode(value);
            head = insert_head(head, nn);
        }
        else if (ch == 2)
        {
            printf("enter position: ");
            scanf("%d", &pos);
            if (pos >= 1 && pos <= list_size(head) + 1)
            {
                int value;
                printf("enter value: ");
                scanf("%d", &value);
                nn = createNode(value);
                head = insert_nth(head, nn, pos);
            }
            else
            {
                printf("invalid position.\n");
            }
        }
        else if (ch == 3)
        {
            int value;
            printf("enter value: ");
            scanf("%d", &value);
            nn = createNode(value);
            head = insert_tail(head, nn);
        }
        else if (ch == 4)
        {
            head = delete_head(head);
        }
        else if (ch == 5)
        {
            printf("enter position: ");
            scanf("%d", &pos);
            if (pos >= 1 && pos <= list_size(head))
            {
                head = delete_nth(head, pos);
            }
            else
            {
                printf("invalid position.\n");
            }
        }
        else if (ch == 6)
        {
            head = delete_tail(head);
        }
        else if (ch == 8)
        {
            printf("list size: %d\n\n", list_size(head));
        }
        else if (ch == 9)
        {
            printList(head);
        }
        else if (ch == 11)
        {
            int N;
            printf("\nEnter no of random values to generate : ");
            scanf("%d", &N);
            head = insert_delete_randomly(head, N);
        }
        else
        {
            printf("Invalid choice. Please try again...\n\n");
        }
        ch = menu();
    }
}

int menu()
{
    int ch;
    printf("1. create node (head)\n");
    printf("2. create node (nth pos)\n");
    printf("3. create node (tail)\n");
    printf("4. delete node (head)\n");
    printf("5. delete node (nth pos)\n");
    printf("6. delete node (tail)\n");
    printf("8.List size\n");
    printf("9.Print List\n");
    printf("11. Insert_Delete_Randomly\n");
    printf("0. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

node *createNode(int value)
{
    node *temp;
    temp = new node();
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void printList(node *temp)
{
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node *insert_head(node *head, node *nn)
{

    if (head == NULL)
    {
        head = nn;
    }
    else
    {
        nn->next = head;
        head = nn;
    }

    return head;
}

node *insert_tail(node *head, node *nn)
{
    if (head == NULL)
    {
        head = nn;
    }
    else
    {
        node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    return head;
}

node *insert_nth(node *head, node *nn, int n)
{
    node *temp;
    if (n == 1)
        head = insert_head(head, nn);
    else if (n == list_size(head) + 1)
        head = insert_tail(head, nn);
    else
    {
        temp = head;
        while (n - 2 > 0)
        {
            temp = temp->next;
            n--;
        }
        nn->next = temp->next;
        temp->next = nn;
    }

    return head;
}

int list_size(node *temp)
{
    int i = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

node *delete_head(node *head)
{
    if (head == NULL)
    {
        printf("Nothing to delete.\n\n");
    }
    else
    {
        node *temp;
        temp = head;
        head = head->next;
        printf("%d deleted\n\n", temp->data);
        delete (temp);
    }
    return head;
}

node *delete_tail(node *head)
{
    if (head == NULL)
    {
        printf("Nothing to delete.\n\n");
    }
    else if (list_size(head) == 1)
    {
        head = delete_head(head);
    }
    else
    {
        node *temp;
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        printf("%d deleted\n\n", temp->next->data);
        delete (temp->next);
        temp->next = NULL;
    }
    return head;
}

node *delete_nth(node *head, int n)
{

    if (head == NULL)
    {
        printf("Nothing to delete.\n\n");
    }
    else if (n == 1)
    {

        head = delete_head(head);
    }
    else if (list_size(head) == n)
    {

        head = delete_tail(head);
    }
    else
    {

        node *pv, *dlt;
        pv = head;
        while (n - 2 > 0)
        {
            pv = pv->next;
            n--;
        }
        dlt = pv->next;
        pv->next = dlt->next;
        printf("%d deleted\n\n", dlt->data);
        delete (dlt);
    }
    return head;
}
node *insert_delete_randomly(node *head, int n)
{
    int randomValue;
    for (int i = 0; i < n; i++)
    {
        randomValue = rand() % 100 + 1; // making values in range
        if (valueExits(head, randomValue))
            head = deleteNode(head, randomValue);
        if (randomValue % 2 == 0)
        {
            head = insert_head(head, createNode(randomValue));
        }
        else
            head = insert_tail(head, createNode(randomValue));
    }
    return head;
}

bool valueExits(node *head, int x)
{
    node *current = head;
    while (current != NULL)
    {
        if (current->data == x)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
node *deleteNode(node *head, int value)
{

    node *temp = head, *prev;
    if (temp != NULL && temp->data == value)
    {
        head = temp->next;
        printf("%d deleted\n\n", temp->data);
        delete (temp);
        return head;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return head;
    prev->next = temp->next;
    printf("%d deleted\n\n", temp->data);
    delete (temp);
    return head;
}

