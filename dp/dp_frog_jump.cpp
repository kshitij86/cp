#include <bits/stdc++.h>
using namespace std;

//a frog has to jump to the last stair and there is an amount of energy required to jump each step
//return the minimum amount of energy needed to reach the end
//at each step, the absolute difference of energy index values is the amount of energy needed to make that jump
//the frog can jump only one or two steps


int min_frog_jump(int n, vector<int> &energy) {
	//no jump needed to reach the starting index, and no energy is used
	if (n == 0)
		return 0;

	/*
		we try out all possible ways for make jump to every single step
		1. left - make only one jump forward, and see what energy you use, value is given as f(n-1) + abs(energy[n] - energy[n-1])
		2. right - make only two jump forward, and see what energy you use, value is given as f(n-2) + abs(energy[n] - energy[n-2])
		3. pick the minimum
	*/

	int left = min_frog_jump(n - 1, energy) + abs(energy[n - 1] - energy[n]);
	int right = INT_MAX;
	if (n > 1)
		//jumping two steps can be done only if we have two steps behind us
		right = min_frog_jump(n - 2, energy) + abs(energy[n - 2] - energy[n]);

	// cout << "left: " << left << " right: " << right << endl;

	return min(left, right);

}

int min_frog_jump_memoized(int n, vector<int> &energy, vector<int> &dp) {
	//the problem has a lot of overlapping subproblems
	//so we can memoize the solutions by storing in dp array
	if (n == 0)
		return 0;
	if (dp[n] == -1) {
		int left = min_frog_jump_memoized(n - 1, energy, dp) + abs(energy[n - 1] - energy[n]);
		int right = INT_MAX;
		if (n > 1)
			right = min_frog_jump_memoized(n - 2, energy, dp) + abs(energy[n - 2] - energy[n]);
		dp[n] = min(left, right);
	}

	return dp[n];
}

int min_frog_jump_tabulated(int n, vector<int> &energy) {
	//non recursive bottom up approach
	int left, right = INT_MAX;;
	vector<int> dp(n, -1);
	dp[0] = 0;
	//go forward from the smallest subproblem towards larger one
	//no need to check if index is -1 as always a valid value is present before the current index as we correctly calculated it previously
	for (int i = 1; i < n; i++) {
		left = dp[n - 1] + abs(energy[i - 1] - energy[i]);
		if (i > 1)
			right = dp[n - 2] + abs(energy[n - 2] - energy[i]);

		dp[i] = min(left, right);
	}

	return dp[n - 1];
}

int min_frog_jump_optimized(int n, vector<int> energy) {
	//fully optimized O(1) space solution
	//since at any point off time we need a maximum of two previous values, it makes sense to store only 2
	int prev1 = 0, prev2 = 0, ans;
	for (int i = 1; i < n; i++) {
		int first = prev1 + abs(energy[i - 1] - energy[i]);
		int second = INT_MAX;
		if (i > 1)
			second = prev2 + abs(energy[i - 2] - energy[i]);
		ans = min(first, second);
		prev1 = prev2;
		prev2 = ans;
		// cout << "i: " << i << " left: " << first << " right: " << second << " ans: " << ans << endl;
	}
	return ans;

}


int main() {
	//expected output = 10 (index 0 -> index 2)
	vector<int> energy {10, 30, 20};
	int n = energy.size();
	vector<int> dp(n, -1);


	// cout << min_frog_jump(n - 1, energy) << endl;
	// cout << min_frog_jump_memoized(n - 1, energy, dp) << endl;
	// cout << min_frog_jump_memoized(n - 1, energy, dp) << endl;
	cout << min_frog_jump_optimized(n, energy) << endl;

}