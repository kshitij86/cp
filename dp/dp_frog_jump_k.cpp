#include <bits/stdc++.h>
using namespace std;

/*
	This time the frog can jump a maximum of K steps forward.
	That means in our recursion, we have to keep track of K previous steps.
	This can be done by looping K times over, and using bottom up DP
*/

//we need to consider the minimum of k previous choices for any step
//last time it was only two
//T(n) = min(T(n-1) + cost(n-1), T(n-2) + cost(n-2))
//Now it will depend on k values
//T(n) = min(T(n-1) + cost(n-1), T(n-2) + cost(n-2),...,T(n-k) + cost(n-k))

int min_frog_jump_k(int n, vector<int> &energy, int k) {
	if (n == 0)
		return 0;


	//determines the min_jump_energy needed at this index/input
	int min_jump_energy = INT_MAX;
	for (int j = 1; j <= k; j++) {
		//non-memoized, non-tabulated solution, will call recurrence each time
		//need a check to maintain array bounds
		//if we are at 5th index, we cannot check 6 indices behind
		int jump_energy = INT_MAX;
		if (n - j >= 0)
			jump_energy = min_frog_jump_k(n - j, energy, k) + abs(energy[n - j] - energy[n]);
		min_jump_energy = min(min_jump_energy, jump_energy);
	}

	return min_jump_energy;
}

//needs to be memoized and tabulated
//cannot be sapce optimized

int main() {
	//expected output = 10
	vector<int> energy {10, 30, 20};
	int n = energy.size();
	int k = 2;
	vector<int> dp(n, -1);

	cout << min_frog_jump_k(n - 1, energy, k) << endl;
}