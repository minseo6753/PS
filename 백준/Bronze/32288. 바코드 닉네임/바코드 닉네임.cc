#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'l')cout << 'L';
		else cout << 'i';
	}
}