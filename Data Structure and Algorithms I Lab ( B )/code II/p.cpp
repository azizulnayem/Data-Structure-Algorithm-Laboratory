// C++ program for finding postorder
// traversal of BST from preorder traversal
#include <bits/stdc++.h>
using namespace std;

// Function to find postorder traversal from
// preorder traversal.
void findPostOrderUtil(int pre[], int n, int minval,
					int maxval, int& preIndex)
{

	// If entire preorder array is traversed then
	// return as no more element is left to be
	// added to post order array.
	if (preIndex == n)
		return;

	// If array element does not lie in range specified,
	// then it is not part of current subtree.
	if (pre[preIndex] < minval || pre[preIndex] > maxval) {
		return;
	}

	// Store current value, to be printed later, after
	// printing left and right subtrees. Increment
	// preIndex to find left and right subtrees,
	// and pass this updated value to recursive calls.
	int val = pre[preIndex];
	preIndex++;

	// All elements with value between minval and val
	// lie in left subtree.
	findPostOrderUtil(pre, n, minval, val, preIndex);

	// All elements with value between val and maxval
	// lie in right subtree.
	findPostOrderUtil(pre, n, val, maxval, preIndex);

	cout << val << " ";
}

// Function to find postorder traversal.
void findPostOrder(int pre[], int n)
{

	// To store index of element to be
	// traversed next in preorder array.
	// This is passed by reference to
	// utility function.
	int preIndex = 0;

	findPostOrderUtil(pre, n, INT_MIN, INT_MAX, preIndex);
}

// Driver code
int main()
{
	int pre[] = { 18,26,27,19,29,40,37,66,57,85,94,90,68,52,35 };

	int n = sizeof(pre) / sizeof(pre[0]);

	// Calling function
	findPostOrder(pre, n);
	return 0;
}
