#include <stdio.h>

struct Node
{
   int data;
   struct Node *left, *right;
};

typedef struct Node node;


void inorder(node *root);
node *insert_BST(node *root, node *nn);
Node *search_BST(node *root, int nm);
Node *delete_BST(node *root, int value);
int nm;
int value;
int menu();
void postorder(node *root);
void preorder(node *root);

int main()

{
    // printf("hello\n");
     node *root = NULL, *nn;
     int ch;
     ch = menu();
    while (ch != 0)

    {
       if (ch == 1)
         {
            nn = new node();
            nn->left = NULL;
            nn->right = NULL;
            printf("enter value: ");
            scanf("%d", &nn->data);
            root = insert_BST(root, nn);
        }
        else if (ch == 2)
        {
            printf("Enter value to search : ");
            scanf("%d", &nm);
            root = search_BST(root, nm);
        }
        else if (ch == 3)
        {
            printf("Enter value to delete : ");
            scanf("%d", &value);
            root = delete_BST(root, value);
        }
        else if (ch == 4)
        {
            preorder(root);
            printf("\n\n");
        }
        else if (ch == 5)
        {
            inorder(root);
            printf("\n\n");
        }
        else if (ch == 6)
        {
            postorder(root);
            printf("\n\n");
        }
        else
        {
            printf("invalid choice.\n\n");
        }
        ch = menu();
    }
    return 0;
}

int menu()
{
    printf("1. insert\n");
    printf("2. search\n");
    printf("3. delete\n");
    printf("4. preorder\n");
    printf("5. inorder\n");
    printf("6. postorder\n");
    printf("0. exit\n");
    int x;
    printf("enter your choice: ");
    scanf("%d", &x);
    return x;
}

node *insert_BST(node *root, node *nn)
{
    if (root == NULL)
    {
        return nn;
    }
    else if (root->data > nn->data)
    {
        root->left = insert_BST(root->left, nn);
    }
    else
    {
        root->right = insert_BST(root->right, nn);
    }
    return root;
}

Node *search_BST(node *root, int ss)

{
    int ad = 0;
    node *cap = new node;
    cap = root;
    while (cap != NULL)
    {
        ad++;
        if (cap->data == ss)
        {
            printf("\ndata found at ad: %d\n", ad);
            return root;
        }
        else if (cap->data > ss)
            cap = cap->left;
        else
            cap = cap->right;
    }

    printf("\ndata not found at ad:%d\n", ad);
    return root;
}

Node *delete_BST(node *root, int num)
{
    if (root == NULL)
        return root;
    if (num < root->data)
        root->left = delete_BST(root->left, num);

    else if (num > root->data)

        root->right = delete_BST(root->right, num);
    else
    {

        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
    }
    return root;
}


void inorder(node *root)
{
    if (root == NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
