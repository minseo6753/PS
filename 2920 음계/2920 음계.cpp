#include <iostream>
using namespace std;
int main() {
	bool t = true;
	int a;
	cin >> a;
	int b = a;

	for (int i = 1; i < 8; i++) {
		
		int a;
		cin >> a;
		
		
		if ((b - a) != 1 and (a - b) != 1) {
			t = false;
		}
		b = a;
	}

	if (t) {
		if (b == 1) {
			cout << "descending";
		}
		else {
			cout << "ascending";
		}
	}
	else {
		cout << "mixed";
	}
	return 0;
	
}