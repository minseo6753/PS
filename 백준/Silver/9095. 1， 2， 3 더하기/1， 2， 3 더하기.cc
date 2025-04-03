#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int>v(11);
	v[1] = 1;
	v[2] = 2;
	v[3] = 4;
	for (int i = 4; i < 11; i++) {
		v[i] = v[i - 3] + v[i - 2] + v[i - 1];
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << v[n] << '\n';
	}
}