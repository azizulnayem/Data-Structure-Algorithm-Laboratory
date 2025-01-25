#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

TreeNode* root = NULL;

TreeNode* createTreeNode(int data)
{
    TreeNode* temp = new TreeNode();
    temp->value = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
}

void Insert(int data)
{
    if(root==NULL)
    {
        root = createTreeNode(data);
        return;
    }

    TreeNode* tempExtra = NULL;
    TreeNode* temp = root;

    while(temp!=NULL)
    {
        tempExtra = temp;
        if(data<temp->value)
            temp = temp->leftChild;
        else
            temp = temp->rightChild;
    }

    if(data < tempExtra->value)
        tempExtra->leftChild = createTreeNode(data);
    else
        tempExtra->rightChild = createTreeNode(data);
}

TreeNode* Search(int data)
{
    TreeNode* temp = root;

    while(temp!=NULL)
    {
        if(data==temp->value) return temp;
        else if(data<temp->value) temp = temp->leftChild;
        else temp = temp->rightChild;
    }
    return NULL;
}

void Inorder(TreeNode* root)
{
    if(root!=NULL)
    {
        Inorder(root->leftChild);
        cout << root->value << " ";
        Inorder(root->rightChild);
    }
}

void Delete(int data)
{

}

int main()
{

    return 0;
}
