#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val < node->val) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }

        return node;
    }

    void inOrderTraversal(TreeNode* node, int& k, int& result) {
        if (node == nullptr || k == 0) {
            return;
        }

        inOrderTraversal(node->left, k, result);
        k--;
        if (k == 0) {
            result = node->val;
            return;
        }
        inOrderTraversal(node->right, k, result);
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    int kthSmallest(int k) {
        int result = -1;
        inOrderTraversal(root, k, result);
        return result;
    }
};

int main() {
    int n, k;
    std::cin >> n >> k;

    BST bst;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        bst.insert(num);
    }

    int kth = bst.kthSmallest(k);
    std::cout << "The kth smallest element is: " << kth << std::endl;

    return 0;
}
