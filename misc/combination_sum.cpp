//https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=8

#include <bits/stdc++.h>
using namespace std;

void combination_sum(int ind, int sum_left, vector<int> &ds, int *arr, int n) {
	//prints the ways in which a given sum can be made, contiguous or not

	if (ind == n) {
		if (sum_left == 0) {
			//if target is reached print everything in the data structure
			for (auto it : ds) {
				cout << it << " ";
			}
			cout << endl;
		}
		return;
	}

	if (arr[ind] <= sum_left) {
		//take this element if it is possible
		ds.push_back(arr[ind]);
		combination_sum(ind, sum_left - arr[ind], ds, arr, n);
		//if element is added, then only is there a need to remove it so even popping from the ds happens in if stmt
		ds.pop_back();
	}
	//but the next index can be called if the current index was not added so that is independent of the ind value
	//don't take it and see it it is possible to make sum
	combination_sum(ind + 1, sum_left, ds, arr, n);
}

int main() {
	//combination sum, try to make a sum of k using an element from array as many times as possible
	/* 	at each step  we have two choices, either to pick or to not pick that index
		we can pick it as many times as possible
		all numbers are positive, so if current_index exceeds the sum we are trying to make, we need to return failure
		if the sum we are trying to make is zero, we also return successfully
	*/
	int arr[] = {1, 2, 3, 4};
	int k = 10;
	int n = sizeof(arr) / sizeof(int);
	vector<int> ds;

	combination_sum(0, k, ds, arr, n);

}