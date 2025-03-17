#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int r;
		string s;
		cin >> r >> s;
		for (int j = 0; j < s.size(); j++) {
			for (int p = 0; p < r; p++) {
				cout << s[j];
			}
		}
		cout << endl;
	}
}