#include<stdio.h>
#include<stdlib.h>


#define FAIL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * list;

void initializeList()
{
    list = 0;  //initially set to NULL
}

void insertItem(int item) //insert at the beginning of the linked list
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->next = list ; //point to previous first node
	list = newNode ; //set list to point to new node as this is now the first node
}


int deleteItem(int item)
{
	struct listNode *curr, *prev ;
	curr = list ; //start at the beginning
	while (curr != 0)
	{
		if (curr->item == item) break ;
		prev = curr;
		curr = curr->next ; //move to next node
	}
	if (curr == 0) return FAIL_VALUE ; //item not found to delete
	if (curr == list) //delete the first node
	{
		list = list->next ;
		free(curr) ;
	}
	else
	{
		prev->next = curr->next ;
		free(curr);
	}
	return SUCCESS_VALUE;

}


struct listNode * searchItem(int item)
{
	struct listNode * curr ;
	curr = list ; //start at the beginning
	while (curr != 0)
	{
		if (curr->item == item) return curr ;
		curr = curr->next ; //move to next node
	}
	return 0 ; // not found; 0 means invalid pointer in C, also called NULL value in C
}

void printList()
{
    struct listNode * curr;
    curr = list;
    while(curr!=0)
    {
        printf("%d->", curr->item);
        curr = curr->next;
    }
    printf("\n");
}

int getListSize(struct listNode *list)
{
    int length=0;
    while(list!=NULL){
        list=list->next;
        length++;
    }
    return length;
}

void insertLast(int item)
{
    struct listNode *Node, *temp;
    Node=(struct listNode*)malloc(sizeof(struct listNode));

     if(Node!=NULL) {
        Node->item=item;
        Node->next=NULL;
        temp=list;
        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=Node;
        printf("Insert successful\n");
    }
}

int insertBefore(int oldItem, int newItem)
{

}

int deleteAfter(int item)
{
    struct listNode *current;
    current=list;
    while(current!=0){
        if(current->item==item){
            current->next=current->next->next;
            return;
        }
        current=current->next;
    }
}

int deleteLast()
{
    struct listNode *toDelete, *secondLastNode;
    if(list==NULL){
        printf("List is empty.\n");
    }
    else{
        toDelete=list;
        secondLastNode=list;
        while(toDelete->next!=NULL){
            secondLastNode=toDelete;
            toDelete=toDelete->next;
        }
        if(toDelete==list){
            list=NULL;
        }
        else{
            secondLastNode->next=NULL;
        }
        free(toDelete);
        printf("Last element deleted.\n");
    }
}



int main(void)
{
    initializeList();
    while(1)
    {
        printf("*******************************************************************\n");
        printf("1. Insert new item. 2. Delete item. 3. Search item. 4.Insert Last.  \n");
        printf("5. Insert Before. 6. Delete After. 7. Delete Last. 8.Get List Size 9. Print. 10. exit.\n");

        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("give an item to insert: ");
            int item;
            scanf("%d", &item);
            insertItem(item);
            printf("inserted successfully\n");
        }
        else if(choice==2)
        {
            printf("give an item to delete: ");
            int item;
            scanf("%d", &item);
            int res=deleteItem(item);
            if(res==SUCCESS_VALUE)
                printf("deleted successfully\n");
            else
                printf("delete unsuccessful\n");
        }
        else if(choice==3)
        {
            int item;
            printf("give an item to search: ");
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(choice==4){
            int item;
            printf("Enter item : ");
            scanf("%d",&item);
            insertLast(item);
        }
        else if(choice==5){

        }
        else if(choice==6){
            int item;
            printf("Enter item : ");
            scanf("%d",&item);
            deleteAfter(item);
            printf("Delete successful\n");
        }
        else if(choice==7){
            int click;
            printf(" Want to delete last item press 1.\n");
            scanf("%d",&click);
            if(click==1){
                deleteLast();
            }
        }
        else if (choice==8){
            printf("Linked List Size: %d\n",getListSize(list));
        }
        else if(choice==9)
        {
            printList();
        }
        else if(choice==10)
        {
            break;
        }
    }

}
