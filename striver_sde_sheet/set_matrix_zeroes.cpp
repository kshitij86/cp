//https://takeuforward.org/data-structure/set-matrix-zero/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void print(vector<vector<int>> matrix) {
	for (auto i : matrix) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}

void solve(vector<vector<int>> matrix) {
	int n = matrix.size(), m = matrix[0].size();
	// O(N^2) in the worst case, all matrix elements are zero
	set<pair<int, int>> hash;

	// count all the original zeros in matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				hash.insert(make_pair(i, j));
			}
		}
	}

	// O(n * m * (n+m)), the (n+m) is for setting rows & cols to zero
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0 && hash.find(make_pair(i, j)) != hash.end()) {
				// set the column as zero, because row is changing
				for (int k = 0; k < n; k++) {
					matrix[k][j] = 0;
				}
				// set the row as zero, because column is changing
				for (int l = 0; l < m; l++) {
					matrix[i][l] = 0;
				}
			}
		}
	}

	print(matrix);
}

void strive(vector<vector<int>> matrix) {
	/**
	 * one approach is to take two arrays, one of size - row
	 * one of size column and set the corrsponding entries to zero
	 *
	 * then traverse this and find if any entry is zero, then set that in the ans matrix as zero
	 *
	 * extra space - O(N+M)
	 *
	 */

	// need to set is to -1 as c++ by default also gives zero
	// and zero is needed here to identify the correct index
	vector<int> row(matrix.size(), -1);
	vector<int> col(matrix[0].size(), -1);

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 0) {
				row[i] = 0;
				col[j] = 0;
			}
		}
	}

	// same as remembering the indices where zero was
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			// there is a zero in my row or col that will affect me
			if (row[i] == 0 || col[j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}

	print(matrix);
}

int main() {
	vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
	strive(matrix);
	cout << endl;

	vector<vector<int>> m2 = matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
	strive(m2);
}