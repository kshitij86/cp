#include <bits/stdc++.h>
using namespace std;

// array contains non-zero, positive integers only
//problem to return the maximum sum subsequence in the array
//the only costraint is that the elements of the subsequence shouls be strictly non-adjacent

int max_non_adjacent_sum(int index, vector<int> &arr) {
	//procedure is simple, we either pick this element, or we don't pick it
	/*
		Two branches of recusrion, pick and no pick
		1. If this element is picked, then we look for the index-2 element, as index-1 cannott be picked to keep the subsequence non-adjacent
		2. If it is not picked, then we can take the index-1 element
		3. Return the best of both of them
	*/
	if (index == 0)
		return arr[0];
	if (index < 0)
		return 0; //this is some invalid index, so it cannot give any sum

	int pick = max_non_adjacent_sum(index - 2, arr) + arr[index]; //as this element is picked, skip the previous one
	int not_pick = max_non_adjacent_sum(index - 1, arr);

	return max(pick, not_pick);
}

int max_non_adjacent_sum_memoized(int index, vector<int> &arr, vector<int> &dp) {
	if (index == 0)
		return arr[0];
	if (index < 0)
		return 0;

	//now make a choice on whether to pick this element or not
	if (dp[index] == -1) {
		int pick = max_non_adjacent_sum_memoized(index - 2, arr, dp) + arr[index];
		int not_pick = max_non_adjacent_sum_memoized(index - 1, arr, dp);
		dp[index] = max(pick, not_pick);
	}
	return dp[index];
}

int max_non_adjacent_sum_tabulated(int index, vector<int> &arr, vector<int> &dp) {
	//tabulated non-recursive solution
	for (int i = 1; i < index; i++) {
		//we can take the i-2 element only if that index exists
		//but we can always take the current element in the pick case
		//so pick case is initilaized with that
		int pick = arr[i];
		if (index > 1)
			pick += dp[i - 2];
		int not_pick = dp[i - 1];
		dp[i] = max(pick, not_pick);
		// cout << "i: " << i << " pick: " << pick << " not_pick: " << not_pick << endl;
	}

	return dp[index - 1];
}

int max_non_adjacent_sum_space_optimized(int index, vector<int> &arr) {
	//O(1) space solution
	//since we only depend on two previous values at any step, we can use two variables, in place of array
	int prev_pick = 0; //corresponds to i-2 choice; at index = 1, there is no i-2 choice so it adds sum of zero
	int prev_not_pick = arr[0]; //corresponds to i-1 choice; at index = 1; you can choose to not pick this element and take the previous element, take the max
	int ans = 0;
	for (int i = 1; i < index; i++) {
		int fs, ss;
		//pick this element and try to not not pick previous
		fs = arr[i];
		if (i > 1)
			fs += prev_pick; //as you have picked this element, how about the i-2 choice
		ss = prev_not_pick; //not picked this element so you still have i-1 choice
		ans = max(fs, ss); //pick the best
		prev_pick = prev_not_pick;
		prev_not_pick = ans;
	}
	return ans;
}

int main() {
	//expected output = 140
	vector<int> arr {10, 20, 30, 60, 100, 30};
	int n = arr.size();
	vector<int> dp(n, -1);
	dp[0] = arr[0];

	// cout << max_non_adjacent_sum(n - 1, arr) << endl;
	// cout << max_non_adjacent_sum_memoized(n - 1, arr, dp) << endl;
	// cout << max_non_adjacent_sum_tabulated(n, arr, dp) << endl;
	cout << max_non_adjacent_sum_space_optimized(n, arr) << endl;
}
