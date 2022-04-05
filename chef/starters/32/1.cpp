#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll t, n, x, y;
	string s;
	
	cin >> t;
	while(t--){
		cin >> n >> x >> y >> s;

		bool one = false, zero = false; 
		for(int i=0; i<n; i++){
			if(s[i] == '1')
				one = true;
			if(s[i] == '0')
				zero  = true;
		}

		if(one && zero){
			cout << min(x, y);
		} else {
			cout << 0;
		}
		cout << endl;
	}

}