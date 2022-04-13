//https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * [[1,2], [3,4]] -> non overlapping
 * [[1,3], [2,6]] ->
 * 		---
 *       -----
 *
 * [[2,3], [1,6]]
 *
 * ------
 *  --
 */

void print(vector<vector<int>> a) {
	for (auto i : a) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}

bool cmp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

/**
 * First sort the array
 * The idea is to go through each interval and consider if other intervals can be merged
 *
 *
 *
 */

void solve(vector<vector<int>> intervals) {
	/**
	 * intervals should be sorted to apply this approach
	 *
	 * O(N^2) solution
	 */
	vector<vector<int>> ans;
	sort(intervals.begin(), intervals.end(), cmp);

	for (int i = 0; i < intervals.size(); i++) {
		int start = intervals[i][0], end = intervals[i][1];

		if (!ans.empty()) {
			// to make sure there already are some intervals
			// interval will be mergable only if they overlap
			// if some interval lies completely inside another
			if (start <= ans.back()[1]) {
				/**
				 * this is possible because the array is sorted
				 * [1,3]
				 * ans - [[2, 6]]
				 *
				 */
				continue;
			}
		}


		for (int j = i + 1; j < intervals.size(); j++) {

			// the current outer interval ends after this one
			// the outer interval ends after the j one starts
			// outer = [4,5]
			// inner = [2,3]
			if (intervals[j][0] <= end) {
				end = intervals[j][1];
			}
		}

		ans.push_back({start, end});

	}
	// now after this part, any intervals that are left in the intervals array can be merged with ans

	print(ans);
}


int main() {
	vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

	solve(intervals);
}