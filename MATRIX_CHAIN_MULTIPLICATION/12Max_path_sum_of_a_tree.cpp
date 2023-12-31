#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left, *right;
};

struct Node* newNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return (newNode);
}
int findMaxUtil(Node* root, int &res)
{
	if (root == NULL)
		return 0;

	// l and r store maximum path sum going through left and
	// right child of root respectively
	int l = findMaxUtil(root->left,res);
	int r = findMaxUtil(root->right,res);

	// Max path for parent call of root. This path must
	// include at-most one child of root
	int max_single = max(max(l, r) + root->data, root->data);

	// Max Top represents the sum when the Node under
	// consideration is the root of the maxsum path and no
	// ancestors of root are there in max sum path
	int max_top = max(max_single, l + r + root->data);

	res = max(res, max_top); // Store the Maximum Result.

	return max_single;
}


int findMaxSum(Node *root)
{

	int res = INT_MIN;


	findMaxUtil(root, res);
	return res;
}

int main(void)
{
	struct Node *root = newNode(10);
	root->left	 = newNode(2);
	root->right	 = newNode(10);
	root->left->left = newNode(20);
	root->left->right = newNode(1);
	root->right->right = newNode(-25);
	root->right->right->left = newNode(3);
	root->right->right->right = newNode(4);
	cout << "Max path sum is " << findMaxSum(root);
	return 0;
}
