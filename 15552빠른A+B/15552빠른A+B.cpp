#include<iostream>
using namespace std;

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	int a, b;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a + b << '\n';
	}
}