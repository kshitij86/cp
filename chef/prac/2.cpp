#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// https://www.codechef.com/LP2TO305/problems/SELINA

int main(){
	ll t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int g[26];
		memset(g, 0, sizeof(g));
		for(int i=0; i<s.length(); i++){
			g[s[i] - 'a']++;
		}

		int ans = -1;
		for(int i=0; i<26; i++){
			if(g[i]%2){
				ans = i;
				break;
			}
		}

		if(ans == -1){
			cout << ans << endl;
		} else {
			cout << (char)(ans+97) << endl;
		}
	}
}		