#include<iostream>
using namespace std;

int main() {

	int a;

	cin >> a;

	bool t=true;

	if (a == 1) {
		for (int i = 2; i <= 8; i++) {
			int b;
			cin >> b;
			if (b != i) {
				t = false;
			}
		}
	}
	else if (a == 8) {
		for (int i = 7; i >= 1; i--) {
			int b;
			cin >> b;
			if (b != i) {
				t = false;
			}
		}
	}
	else {
		t = false;
	}
	if (t) {
		if (a == 1) {
			cout << "ascending";
		}
		if (a == 8) {
			cout << "descending";
		}
	}
	else {
		cout << "mixed";
	}
}