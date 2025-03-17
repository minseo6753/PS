#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	while (a != 0) {
		
		a *= a;
		b *= b;
		c *= c;
		if (a > b && a > c) {
			if (b + c == a)cout << "right";
			else cout << "wrong";
		}
		else if (b > a && b > c) {
			if (a + c == b)cout << "right";
			else cout << "wrong";
		}
		else if (c > a && c > b) {
			if (a + b == c) cout << "right";
			else cout << "wrong";
		}
		cout << endl;
		cin >> a >> b >> c;
	}
}