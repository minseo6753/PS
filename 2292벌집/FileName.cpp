#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n -= 1;
	int i;
	for (i = 6; n > 0; i += 6) {
		n -= i;
	}
	cout << i / 6;
}