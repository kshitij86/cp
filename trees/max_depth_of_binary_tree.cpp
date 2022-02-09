// https://www.youtube.com/watch?v=eD3tmO66aBA&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=15

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

int max_height_of_tree(struct node *root) {
	//find the max height of the tree
	/*procedure is:
		1. the search always terminates at a leaf
		2. otherwise we add one to maximum of the left and right nodes
		3. recursion is called for both the left and right nodes
	*/

	if (!root || (!root->left && !root->right)) return 0;

	return 1 + max(max_height_of_tree(root->left), max_height_of_tree(root->right));
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

	struct node *root2 = new node(1);
	root2->left = new node(2);

	cout << max_height_of_tree(root) << endl;
	cout << max_height_of_tree(root2) << endl;

}