// https://www.youtube.com/watch?v=Yt50Jfbd8Po&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=16

#include <bits/stdc++.h>
using namespace std;

//definition of balanced tree:
// (height of left subtree) - (height of right subtree) <= 1

struct node {
	int data;
	struct node *left, *right;

	node(int val) {
		data = val;
		left  = NULL;
		right = NULL;
	}
};



void naive_check_balance(struct node *root) {
	//finds the height of every tree and checks if it is balanced
}

int main() {
	struct node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
}