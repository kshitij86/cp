#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n, m, t;

	cin >> t;
	while(t--){
		cin >> n >> m;
		
		n <= m ? cout << n : cout << 2*n - m;
		cout << endl; 
	}
}