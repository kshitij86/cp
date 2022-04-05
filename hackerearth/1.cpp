#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int t, n, k;
	cin >> t; 
	while(t--){
		cin >> n;
		ll a[100001];
		memset(a, 0, sizeof(a));
		for(ll i=0; i<n; i++){
			ll x;
			cin >> x;
			a[x]++; 
		}

		ll x = INT_MAX, y = INT_MIN;
		for(ll i=1; i<=n; i++){
			if(a[i] < x && a[i]){
				x = a[i];
			}
			if(a[i] > y && a[i]){
				y = a[i];
			}
		}
		
		ll ans = x - y == 0 ? 1 : x - y; 
		cout << ans << endl;
	}
}