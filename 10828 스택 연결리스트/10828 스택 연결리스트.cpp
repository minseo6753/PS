#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>arr(n);
	int m = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "push") {
			int x;
			cin >> x;
			arr[m] = x;
			m += 1;

		}
	}
}