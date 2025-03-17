#include<iostream>
using namespace std;

int f(int a, int b) {
	if (a == 0)return b;
	int sum = 0;
	for (int j = 1; j <= b; j++) {
		sum += f(a - 1, j);
	}
	return sum;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int k, n;
		cin >> k >> n;
		cout << f(k, n) << endl;
	}
}