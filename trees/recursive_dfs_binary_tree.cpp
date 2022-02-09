#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left, *right;

	node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

//perform recursive dfs on a binary tree
void recursive_dfs(struct node *root) {
	if (!root) return;

	//uses the system stack to perform recursion
	cout << root->data << " ";
	recursive_dfs(root->left);
	recursive_dfs(root->right);
}

int main() {

	struct node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);

	recursive_dfs(root);
}