#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/permutation-sequence/

void kperm(int index, string a, string ds, vector<int> &map, vector<string> &res) {
	//slow recursive code
	// TC - O(n!)
	if (index == a.size()) {
		res.push_back(ds);
		return;
	}

	for (int i = 0; i < a.size(); i++) {
		if (!map[i]) {
			map[i] = 1;
			ds += a[i];
			kperm(index + 1, a, ds, map, res);
			map[i] = 0;
			ds.pop_back();
		}
	}
}

int main() {
	int n = 9, k = 990;
	string a = "";
	string ds;
	vector<string> res;
	vector<int> map(n, 0);
	int ctr = 0;
	for (int i = '1'; ctr < n; i++) {
		a += i;
		ctr++;
	}

	kperm(0, a, ds, map, res);

	cout << res[k] << endl;
}