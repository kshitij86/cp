#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int c[4] = {0};
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			// captial
			c[0] = 1;
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			//lower
			c[1] = 1;
		}
		else if (s[i] >= '1' && s[i] <= '9') {
			//number
			c[2] = 1;
		}
		else if (s[i] >= ':' && s[i] <= '@') {
			c[3] = 1;
		}
	}


	int ans = 1;
	for (int i = 0; i < 4; i++) {
		if (c[i] != 1) {
			ans = 0;
		}
	}
	cout << ans << endl;
}