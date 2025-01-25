#include<stdio.h>
#include<stdlib.h>

#define FAIL_VALUE -999999
#define SUCCESS_VALUE 999999

struct treeNode
{
    int item;
    struct treeNode * left; //points to left child
    struct treeNode * right; //points to right child
};

struct treeNode * root;


void initializeTree()
{
    root = 0;
}


struct treeNode* searchItem(struct treeNode * node, int item)
{
    if(node==0) return 0;

    if(node->item==item) return node; //found, return node
    struct treeNode * t = 0;
    if(item < node->item)
        t = searchItem(node->left, item); //search in the left sub-tree
    else
        t = searchItem(node->right, item); //search in the right sub-tree
    return t;
};


struct treeNode * makeTreeNode(int item)
{
    struct treeNode * node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};

int insertItem(struct treeNode * node, int item)
{
    if(node==0) //insert as the root as the tree is empty
    {
        struct treeNode * newNode = makeTreeNode(item);
        root = newNode;
        return SUCCESS_VALUE;
    }

    if(node->item==item){
		printf("Already in the tree\n");
		return FAIL_VALUE; //already an item exists, so return NULL
	}
    if(item< node->item && node->left==0) //insert as the left child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->left = newNode;
        return SUCCESS_VALUE;
    }

    if(item>node->item && node->right==0) //insert as the right child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->right = newNode;
        return SUCCESS_VALUE;
    }

    if(item<node->item)
        return insertItem(node->left, item); //insert at left sub-tree
    else
        return insertItem(node->right, item); //insert at right sub-tree
}



int calcNodeHeight(struct treeNode * node) //return height of a node
{
    if(node==0) return -1;
    int l, r;
    l = calcNodeHeight(node->left);
    r = calcNodeHeight(node->right);
    if(l>r) return l+1;
    else return r+1;
}


int calcHeight(int item) //return height of an item in the tree
{
    struct treeNode * node = 0;
    node = searchItem(root, item);
    if(node==0) return -1; //not found
    else return calcNodeHeight(node);
}

int getSize(struct treeNode * node)
{

}


int calcDepth(int item)//return depth of an item in the tree
{
    //write your codes here
}

int deleteItem(struct treeNode * node, int item)
{
    //write your code here, return SUCCESS, FAIL
}

int getMaxItem() //returns the maximum item in the tree
{
    //write your codes here
}


void printInOrder(struct treeNode * node)
{
    if(node==0) return ;

    //print left sub-tree
    printInOrder(node->left);

    //print item
    printf("%d ",node->item);

    //print right sub-tree
    printInOrder(node->right);
}



int main(void)
{
    initializeTree();
    while(1)
    {
        printf("\n***********************************************************************\n");
        printf("1. Insert item. 2. Delete item. 3. Search item. 4. Get height. 5. Print in order.\n");
        printf("6. Print level order. 7. Print post order.  8. Get depth. 9. Get max. \n");
        printf("10. delete K'th smallest . 11. Get subtree sum. 12. Change item. 13. Exit.");
        printf("\n***********************************************************************\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            int res=insertItem(root, item);
            if(res==SUCCESS_VALUE)
                printf("Insertion successful\n");
            else
                printf("Insertion failed\n");
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            int height = calcHeight(item);
            if(height==-1)
                printf("%d Not found\n", item);
            else
                printf("Height of %d = %d\n", item, height);
        }
        else if(ch==5)
        {

            printInOrder(root);

        }
        else if(ch==13)
        {
            break;
        }
    }

}
