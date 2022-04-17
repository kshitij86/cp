#include <vector>
#include <iostream>

using namespace std;

/**
 * cycle detection works by checking if a visited vertex is visted again
 * since graph is undirected, the order of vertices does not matter
 */

bool dfs(int i, vector<int> graph[], vector<int> &vis) {
	vis[i] = 1;
	for (int j = 0; j < graph[i].size(); i++) {
		if (vis[graph[i][j]] == 0) {
			// unvisited vertex
			return dfs(graph[i][j], graph, vis);
		}
		if (vis[graph[i][j]] == 1) {
			return true;
		}
	}
	return false;
}

bool cycle_detect(int n, vector<int> graph[]) {
	vector<int> vis(n + 1, 0);

	for (int i = 0; i < n + 1; i++) {
		if (vis[i] == 0) {
			if (dfs(i, graph, vis)) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	int n = 3;
	vector<int> graph[n + 1];
	graph[0] = {1, 2};
	graph[1] = {0, 2};
	graph[2] = {0, 1};


	cycle_detect(n , graph) ? cout << "has cycle" : cout << "no cycle";
}