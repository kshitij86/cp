//https://takeuforward.org/data-structure/stock-buy-and-sell/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


void solve(vector<int> prices) {
	/**
	 * you can buy on a day and sell on a future day only
	 * means index[buy] < index[sell]
	 */

	// O(N^2)
	// try buying at each day and sell at future
	int glob_max = INT_MIN;
	for (int i = 0; i < prices.size() - 1; i++) {
		int profit = 0;
		for (int j = i + 1; j < prices.size(); j++) {
			profit = max(profit, prices[j] - prices[i]);
		}
		glob_max = max(profit, glob_max);
	}

	cout << glob_max << endl;
}

void strive(vector<int> prices) {
	// single pass O(N) solution
	/**
	 * take two variables mi and ma:
	 * mi is set to the first element, we will find the difference from it
	 * ma = 0
	 *
	 * if(prices[i] > mi){
	 * 		then there may be profit by it at this price, so compare with max and store the difference
	 * } else {
	 * 		if(prices[i] < mi)
	 * 			this is a new minimum and will give steeper(more) profit becaue it is small
	 * 			example - mi = 4
	 * 			after traversal if prices[i] is 3 and there is and index prices[j] = 5 and (i<j)
	 * 			mi will give profit = 5-4 = 1
	 * 			prices[i] will give profit = 5-3 = 2
	 *
	 * 			so if prices[i] < mi, then update mi
	 * }
	 *
	 */

	int mi = prices[0], ma = 0;
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] > mi) {
			// here prices[i] > mi
			ma = max(ma, prices[i] - mi);
		} else {
			// so it can be same or less here
			mi = prices[i];
		}
	}

	cout << ma << endl;
}

int main() {
	vector<int> p1 = {7, 1, 5, 3, 6, 4};
	vector<int> p2 = {7, 6, 4, 3, 1};

	strive(p1);
	strive(p2);
}