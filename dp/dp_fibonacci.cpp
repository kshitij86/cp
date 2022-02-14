#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//find out fibinacci numbers using dynamic programming
ll  dp_fib(int n, vector<ll> &dp) {
	if (n <= 1)
		return n;
	if (dp[n] == -1) {
		// if this value has not been computed yet
		dp[n] = dp_fib(n - 1, dp) + dp_fib(n - 2, dp );
	}
	//this works as follows
	/*
		1. if the value is computed(does not have -1 in it), directly return it
		2. if it is not computed(has a -1 in it), compute it once, store it and then return it
	*/

	return dp[n];
}

int main() {
	ll n = 30;
	//anothe rway to initialize vector
	vector<ll> dp(n + 1 , -1);
	//memset-ting works on arrays because:
	/*
		1. we give it the starting address, the array name is a mnemonic
		2. we provide a default value
		3. we give the count of data that needs to be overwritten with that value

		it works like a certain I/O transfer mechanism
	*/

	dp_fib(n, dp);
	cout << dp[n] << endl;
	return 0;
}