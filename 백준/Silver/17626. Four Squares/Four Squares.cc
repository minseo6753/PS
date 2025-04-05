#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>v(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int num = 4;
		for (int j = 1; j <= sqrt(i); j++) {
			if (v[i - j * j] + 1 < num)num = v[i - j * j] + 1;
		}
		v[i] = num;
	}
	cout << v[n];
}