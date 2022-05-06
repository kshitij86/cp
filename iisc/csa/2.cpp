#include <bits/stdc++.h>
using namespace std;

//Reading input can be tricky due to string so need to brush up on strings
//Cycle detection for digraph and undigraph are different
//Reason is presence of back edges in digraph indicates presence of a cycle
//But in DFS of undigraph, there are only back edges and tree edges
//So same checking visited[] algo will not work
//Since visited[] array will not work, so we need another array



int stoc(string s) {
	int num = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		int x = s[i] - '0';
		num += x * pow(10, s.length() - 1 - i);
	}
	return num;
}


int main() {
	string line;
	map<int, set<int>> g;

	while (getline(cin, line)) {
		int i = 0;
		string emp = "";
		for (; line[i] != ' '; i++) {
			emp += line[i];
		}
		int n = stoc(emp);
		emp  = "";
		i += 4;
		for (; line[i] != '\0'; i++) {
			emp += line[i];
		}
		int m = stoc(emp);

		if (g.find(n) == g.end()) {
			// never seen before
			g[n] = {};
		}
		g[n].insert(m);
	}

	for (auto i : g) {
		cout << i.first << " : ";
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl;
	}

}