// https://www.youtube.com/watch?v=EoAsWbO7sqg&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=9

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


void level_tree(struct node *root) {
	// naive, prints all levels in same line
	queue<struct node*> q;
	q.push(root);

	while (!q.empty()) {
		struct node *temp = q.front(); // return refrence to firsr element of queue
		q.pop(); //delete element from the queue

		cout << temp->data << " ";
		if (temp->left) q.push(temp->left);
		if (temp->right) q.push(temp->right);
	}
}

void proper_level_print(struct node *root) {
	//same function but gives and idea about the actual levels of the tree
	vector<vector<int>> bfs; //data structure to store tree level-wise
	queue<struct node*> q; //queue for bfs
	q.push(root);

	//bfs procedure
	while (!q.empty()) {
		int curr_q_size = q.size(); // get the size of the queue currently
		vector<int> level; //holds the current level fully
		for (int i = 0; i < curr_q_size; i++) {
			//keep popping from the queue until we have popped elements equal to the current level of the queue
			struct node *temp = q.front();
			q.pop();

			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
			level.push_back(temp->data);
		}
		bfs.push_back(level);
	}

	for (auto it : bfs) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}
}

int main() {
	/*
				1
			   / \
			  2   3
			 /
			4

	expected output:

	1
	2 3
	4

	*/

	struct node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);

	proper_level_print(root);

}