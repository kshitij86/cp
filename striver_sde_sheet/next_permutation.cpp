//https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<int> arr) {
	for (auto i : arr) {
		cout << i;
	}
}

void perm_util(int index, vector<int> &cpy, vector<vector<int>> &ans) {
	/**
	 * this method will try to swap the elements at each index
	 *
	 * initial ordering = [1,2,3]
	 * 1. then try going to each index and swap that index with this one
	 * 2. then call the recursive call for the next index and again try to swap aother index with this
	 * 3. no need of map array as only swapping is taking place
	 */
	if (index == cpy.size()) {
		ans.push_back(cpy);
		return;
	}

	// TODO: Important point is that when we start any recursive call, start from this index and not zero
	// This will avoid the repeated permutations
	for (int i = index; i < cpy.size(); i++) {
		int temp = cpy[index];
		cpy[index] = cpy[i];
		cpy[i] = temp;

		perm_util(index + 1, cpy, ans);

		temp = cpy[index];
		cpy[index] = cpy[i];
		cpy[i] = temp;
	}
}

void solve(vector<int> arr) {
	/**
	 * naive solution - generate all permutations, then from that list find the one given and then return the next one
	 * time - O(n!)
	 * space- O(n!)
	 */

	vector<vector<int>> ans;
	vector<int> cpy = arr;
	sort(cpy.begin(), cpy.end());

	perm_util(0, cpy, ans);

	for (auto i : ans) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	int index = -1;
	for (int i = 0; i < ans.size(); i++) {
		bool match = true;
		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] != ans[i][j]) {
				match = false;
			}
		}
		if (match == true) {
			index = i;
		}
	}
	if (index != -1)
		print(ans[index + 1]);
}


void inbuilt(vector<int> arr) {
	// the inbuilt function nex_permutation will also do this
	next_permutation(arr.begin(), arr.end());
	print(arr);
}
int main() {
	vector<int> arr = {1, 3, 2};

	solve(arr);
	cout << endl;
	inbuilt(arr);
}