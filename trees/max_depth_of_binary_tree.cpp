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

void max_height_of_tree(struct node *root) {
	//find the max height of the tree
	/*procedure is:
		1. the search always terminates at a leaf
		2.
	*/

}

int main() {

	struct node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->left->left->left = new node(6);
	root->left->left->left->left = new node(7);
	root->left->left->left->left->left = new node(8);

}