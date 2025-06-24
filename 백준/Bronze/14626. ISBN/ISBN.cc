#include<iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int sum = 0;
	int t = 1;
	int x;
	for (int i = 0; i < 12; i++) {

		if (s[i] == '*') {
			x = t;
		}
		else {
			sum += t*(s[i] - '0');
		}
		t = 4 - t;
	}
	sum += s[12]-'0';
	sum %= 10;
	sum = 10 - sum;
	sum %= 10;
	if (x == 1) {
		cout << sum;
	}
	else {
		int arr[10] = { 0,7,4,1,8,5,2,9,6,3 };
		cout << arr[sum];
	}
}