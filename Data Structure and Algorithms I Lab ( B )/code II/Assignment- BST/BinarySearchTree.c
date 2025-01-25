//Assignment on Binary Search Tree(BST)
//Name: Hasibul Hasan Nirob
//ID: 011201031

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
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
///Task 01
int getSize(struct treeNode * node)
{
    if(node==NULL) return 0;
    else
        return(getSize(node->left)+1+getSize(node->right));
}

///Task 02
int calcDepth(struct treeNode *node,int item)//return depth of an item in the tree
{
    if(node==NULL) return -1;
    int distance=-1; //initialize distance
    if((node->item==item)
        || (distance=calcDepth(node->left,item))>=0
        || (distance=calcDepth(node->right,item))>=0)
        return distance+1;
    return distance;
}
///Task 07
int findSubTreeSum(struct treeNode *node, int item){
    int sum,sumLeft,sumRight;
    sum=sumLeft=sumRight=0;
    if(node==NULL){
        printf("Empty Tree\n");
        return 0;
    }
    else {
        if(node->left!=NULL)
            sumLeft=findSubTreeSum(node->left,item);
        if(node->right!=NULL)
            sumRight=findSubTreeSum(node->right,item);
        sum=node->item+sumLeft+sumRight;
        return sum;
    }
}
///Task 06
int deleteKsmallest(struct treeNode *node,int k){
    if(node==NULL) return NULL;
    struct treeNode *left=deleteKsmallest(node->left,k);
    if(left!=NULL)
        return left;
    k--;
    if(k==0)
        return node;
    return deleteKsmallest(node->right,k);
}
//find inorder successor
struct treeNode *minValueNode(struct treeNode *node) {
  struct treeNode *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}
///Task 04
int deleteItem(struct treeNode * node, int item)
{
    if(node==NULL) return node;
    if(item<node->item)
        node->left=deleteItem(node->left,item);
    else if(item>node->item)
        node->right=deleteItem(node->right,item);

    else {
        if(node->left==NULL){
            struct treeNode *temp=node->right;
            free(node);
            return temp;
        }
        else if(node->right==NULL){
            struct treeNode *temp=node->left;
            free(node);
            return temp;
        }
    struct treeNode *temp = minValueNode(node->right);
    node->item= temp->item;
    node->right = deleteItem(node->right, temp->item);
    }
    return node;
}
///Task 03
int getMaxItem(struct treeNode *node) //returns the maximum item in the tree
{
        if(node==NULL) return INT_MIN;
        int max=node->item;
        int lmax=getMaxItem(node->left);
        int rmax=getMaxItem(node->right);
        if(lmax>max) max=lmax;
        if(rmax>max) max=rmax;
        return max;
}

///Task 05
void printLevelOrder(struct treeNode *node){
    if(node==0) return;
    printLevelOrder(node->left);
    printf("%d ",node->item);
    printLevelOrder(node->right);
}

void printPostOrder(struct treeNode *node){
    if(node==0) return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ",node->item);
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
///Task 08
int changeItem(struct treeNode *node,int oldItem, int newItem){
    node=deleteItem(node,oldItem);
    node=insertItem(node,newItem);
    return node;
}

int main(void)
{
    initializeTree();
    while(1)
    {
        printf("\n***********************************************************************\n");
        printf("1. Insert item. 2. Delete item. 3. Search item. 4. Get height. 5. Print in order.\n");
        printf("6. Print level order. 7. Print post order.  8. Get depth. 9. Get max. \n");
        printf("10. delete K'th smallest . 11. Get subtree sum. 12. Change item. 13. Exit. 14.Size of the tree.");
        printf("\n***********************************************************************\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            printf("Insert an item: ");
            scanf("%d", &item);
            int res=insertItem(root, item);
            if(res==SUCCESS_VALUE)
                printf("Insertion successful\n");
            else
                printf("Insertion failed\n");
        }
        else if(ch==2){
            int item;
            printf("Enter the item want to delete: ");
            scanf("%d",&item);
            int res=deleteItem(root, item);
            printf("Deletion successful.\n");

        }
        else if(ch==3)
        {
            int item;
            printf("Search an item: ");
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            printf("Enter value: ");
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
        else if(ch==6){
            printLevelOrder(root);
        }
        else if(ch==7){
            printPostOrder(root);
        }
        else if(ch==8){
            int item;
            printf("Enter value: ");
            scanf("%d",&item);
            printf("Depth of the tree %d",calcDepth(root,item));
        }
        else if(ch==9){
            printf("Maximum item in the tree: %d\n",getMaxItem(root));
        }
        else if(ch==10){
            printf("Enter the k's smallest value: ");
            int item;
            scanf("%d",&item);
            int delk=deleteItem(root,item);
            deleteKsmallest(root,delk);
        }
        else if(ch==11){
            int item;
            printf("Enter value: ");
            scanf("%d",&item);
            printf("Sum of sub tree: %d",findSubTreeSum(root,item));
        }
        else if(ch==12){
            int olditem,newitem;
            printf("old item: ");
            scanf("%d",&olditem);
            printf("new item: ");
            scanf("%d",&newitem);
            changeItem(root,olditem,newitem);
            printf("Item changed sucessfully\n");
        }
        else if(ch==13)
        {
            break;
        }
        else if(ch==14){
            printf("Size of the tree is %d\n",getSize(root));
        }
    }

}
