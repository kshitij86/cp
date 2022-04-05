#include <bits/stdc++.h>
using namespace std;

int main(){
	string a, b, c;
	int freq[100];
	memset(freq, 0, sizeof(freq)); 
	
	cin >> a >> b >> c;
	for(int i=0; a[i] != '\0'; i++){
		freq[a[i] - 'A']++;
	}
		
	for(int i=0; b[i] != '\0'; i++){
		freq[b[i] - 'A']++;
	}

	for(int i=0; c[i] != '\0'; i++){
		freq[c[i] - 'A']--;
	}
	bool flag = true;
	for(int i=0; i<100; i++){
		if(freq[i] != 0){
			flag = false;
			break;
		}
	}
	
	flag ? cout << "YES" : cout << "NO";
	cout << endl;

}

