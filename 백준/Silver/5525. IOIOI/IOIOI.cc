#include<iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int plen = 3 + 2 * (n - 1);

	string s;
	cin >> s;

	char c = s[0];
	int len = 1;
	int sum = 0;
	for(int i=1;i<m;i++) {
		if (s[i] != c) {
			c = s[i];
			len++;
		}
		else {
			if (s[i - 1] == 'O')len--;
			if (len % 2 == 0)len--;
			if (len >= plen) {
				sum += (len - plen) / 2 + 1;
			}
			len = 1;
		}
	}

	if (len >= plen) {
		sum += (len - plen) / 2 + 1;
	}

	cout << sum;
}

