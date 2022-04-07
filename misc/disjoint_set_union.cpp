#include<bits/stdc++.h>
using namespace std;

/**
 * Used to create groups in the data structure
 * Three main operations -
 * 1. make - create a new independent node
 * 2. find - find the parent of the group
 * 3. union - group two nodes together
 *
 *
 *
 */

vector<int> ans(100, -1);

void print() {
	for (auto i : ans) {
		cout << i << " ";
	}
}


void dsu_make(int v) {
	// create an indepnedent node in the set
	// parent of each new independent node is thar node itself
	ans[v] = v;
}

int dsu_find(int v) {
	int parent = v;
	if (ans[parent] == -1) {
		cout << "node does not exist, create it first" << endl;
		return -1;
	}
	if (v == ans[v]) {
		return v;
	}
	while (parent != ans[parent]) {
		parent = ans[parent];
	}
	return parent;
}

void dsu_union(int a, int b) {
	// neither a nor b may be a parent of their component
	// add the component having a to that of b
	if (ans[a] == -1 || ans[b] == -1) {
		cout << "node does not exist, create it first" << endl;
		return;
	}
	finding out the parent of a node
	while (ans[a] != a) {
		a = ans[a];
	}
	while (ans[b] != b) {
		b = ans[b];
	}
	ans[a] = b;
}


int main() {
	dsu_make(1);
	dsu_make(2);
	dsu_make(3);
	dsu_make(4);
	dsu_make(5);


	// add 1 to 3
	dsu_union(1, 3);

	// add 2 to 4
	dsu_union(2, 4);

	// add the component with 4 to that having 1
	dsu_union(4, 1);

	// expected = 3
	cout << dsu_find(4) << endl;

	dsu_union(5, 2);
	cout << dsu_find(5) << endl;

	dsu_find(6);
}