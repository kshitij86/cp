#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//https://www.codechef.com/problems/JAG

ll dfs(ll n, ll* w) {
	// O(V+E)
	ll comp = 0;
	vector<vector<ll>> g(n, vector<ll> (n));

	stack<ll> p;
	ll visited[n];
	memset(visited, 0, sizeof(visited));

	// construct graph
	for (int i = 0; i < n; i++) {
		// for every weight, find if there is an edge to the jth node
		for (int j = 0; j < n; j++) {
			if ((w[j] - w[i] != (j - i))) {
				g[i][j] = 1;
				g[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			p.push(i);
			comp++;
			while (!p.empty()) {
				ll node = p.top();
				visited[node] = 1;
				p.pop();
				for (int i = 0; i < n; i++) {
					if (g[node][i] == 1 && !visited[i] && node != i) {
						p.push(i);
					}
				}
			}
		}
	}

	return comp;
}

void dsu_make(ll *a, ll v) {
	a[v] = v;
}

ll dsu_find(ll* a, ll v) {
	if (a[v] == v)
		return v;
	return dsu_find(a, a[v]);
}

void dsu_union(ll* a, ll x, ll y) {
	x = dsu_find(a, x);
	y = dsu_find(a, y);
	if (x == y) {
		return;
	}
	a[x] = y;
}

ll dsu(ll n, ll*w) {
	ll cnt = 0;
	ll parent[n];
	memset(parent, -1, sizeof(parent));

	for (int i = 0; i < n; i++) {
		dsu_make(parent, i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (w[j] - w[i] != j - i) {
				dsu_union(parent, i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (parent[i] == i) {
			cnt++;
		}
	}
	return cnt;

}
int main() {
	ll t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		// n by n graph
		ll w[n] = {0};
		for (int i = 0; i < n; i++) {
			cin >> w[i];
		}
		cout << dsu(n, w) << endl;
	}
}