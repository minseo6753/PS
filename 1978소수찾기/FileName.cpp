#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int composite = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			composite++;
			continue;
		}
		for (int j = 2; j < a; j++) {
			if (a % j == 0) {
				composite++;
				break;
			}
		}
	}
	cout << n - composite;
}