#include<stdio.h>
#include<stdlib.h>

#define FAIL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
    struct listNode * prev;
};

struct listNode * list;


void initializeList()
{
    list = 0;  //initially set to NULL
}

void insertFirst(int item) //insert at the beginning
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->prev = 0;
	newNode->next = list;

	if(list!=0) //inserting the first item
    {
        list->prev = newNode;
    }
	list = newNode;
}


int insertBefore( int oldItem, int newItem)
{
    //write your codes here

}

void deleteAfter(int item)
{
    //write your codes here

}


struct listNode * searchItem(int item)
{
	struct listNode * temp ;
	temp = list ; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) return temp ;
		temp = temp->next ; //move to next node
	}
	return 0 ; // not found; 0 means invalid pointer in C, also called NULL value in C
}

void printListForward()
{
    struct listNode * temp;
    temp = list;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

void printListBackward()
{
	//will print the list backward starting from the last position

}


int main(void)
{
    initializeList();
    while(1)
    {
		printf("*******************************************************************\n");
        printf("1. Insert new item. 2. Search item. 3. Print forward. \n");
        printf("4. Insert Before. 5. Delete After. 6. Print backward. 7. exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertFirst(item);
			printf("inserted successfully\n");
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==3)
        {
            printListForward();
        }

        else if(ch==7)
        {
            break;
        }
    }

}
