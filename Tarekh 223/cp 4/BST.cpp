#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

TreeNode* createTreeNode(int data)
{
    TreeNode* temp = new TreeNode();
    temp->value = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    return temp;
}

TreeNode* Insert(int data, TreeNode* root)
{
    if(root==NULL)
    {
        root = createTreeNode(data);
        return root;
    }

    if(data<root->value) root->leftChild = Insert(data, root->leftChild);
    else root->rightChild = Insert(data, root->rightChild);

    return root;
}

void Inorder(TreeNode* root)
{
    if(root==NULL) return;

    Inorder(root->leftChild);
    cout << root->value << " ";
    Inorder(root->rightChild);
}

void Preorder(TreeNode* root)
{
    if(root==NULL) return;

    cout << root->value << " ";
    Preorder(root->leftChild);
    Preorder(root->rightChild);
}

void Postorder(TreeNode* root)
{
    if(root==NULL) return;

    Postorder(root->leftChild);
    Postorder(root->rightChild);
    cout << root->value << " ";
}

TreeNode* Search(int data, TreeNode* root)
{

}


int main()
{
    freopen("input.txt", "r", stdin);
    TreeNode* root = NULL;

    int n; cin >> n;
    for(int i=1;i<=n;i++)
    {
        int temp; cin >> temp;
        root = Insert(temp, root);
    }

    Inorder(root);

    return 0;
}
