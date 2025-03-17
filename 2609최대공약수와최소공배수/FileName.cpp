#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int s, l;
	if (a > b) {
		s = b;
		l = a;
	}
	else {
		s = a;
		l = b;
	}

	for (int i = s; i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			cout << i << endl;
			break;
		}
	}
	
	for (int i = l;; i++) {
		if (i % a == 0 && i % b == 0) {
			cout << i;
			break;
		}
	}
}