#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void showpq(priority_queue<pair<ll, ll>> gq)
{
    priority_queue<pair<ll, ll>> g = gq;
    while (!g.empty()) {
        cout << g.top().first << " : " << g.top().second << endl;
        g.pop();
    }
    cout << endl;
}


int main(){
	ll t, n, k;

	cin >> t;
	while(t--){
		ll mi  = INT_MAX, idx = -1;
		cin >> n >> k;
		ll arr[n];
		for(ll i=0; i<n; i++){
			cin >> arr[i];
		}

		sort(arr, arr+n);
		if(k > n){
			cout << arr[n-1] << endl;
		} else {
			cout << arr[k] << endl;
		}
	}
}