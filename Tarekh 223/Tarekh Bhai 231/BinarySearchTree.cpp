#include<iostream>
#include<stdio.h>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(int data)
    {
        this->value = data;
        this->left = this->right = NULL;
    }
};


void preorder(TreeNode* root)
{
    if(root!=NULL)
    {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

void postorder(TreeNode* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

TreeNode* Insert(int data, TreeNode* root)
{
    if(root==NULL)
    {
        root = new TreeNode(data);
        return root;
    }
    if(data>root->value)
        root->right = Insert(data, root->right);
    else
        root->left = Insert(data, root->left);
    return root;
}

TreeNode* Search(int key, TreeNode* root)
{
    if(root==NULL)
        return NULL;

    if(key==root->value) return root;
    else if(key>root->value) return Search(key, root->right);
    else return Search(key, root->left);
}

TreeNode* Delete(int key, TreeNode* root)
{

}

int main()
{
    TreeNode* root = NULL;

    /// inserting in Binary Search Tree (BST)
    int arr[8] = {15, 12, 17, 16, 19, 5, 14, 13};
    for(int i=0; i<8; i++)
    {
        root = Insert(arr[i], root);
    }

    /// Inorder Traversal
    cout << "Inorder Traversal Sequence: ";
    inorder(root);
    cout << endl;

    /// Search
    TreeNode* temp = Search(20, root);
    if(temp!=NULL)
        cout << "Found the element in BST\n";
    else
        cout << "Not Found the element in BST\n";

}
