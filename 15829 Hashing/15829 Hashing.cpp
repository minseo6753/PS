#include <iostream>
#include<math.h>
using namespace std;

int main() {
	int l;
	cin >> l;
	string s;
	cin >> s;
	long long h = 0;
	string d = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < l; i++) {
		int x = d.find(s[i]);
		long long y=1;
		for (int j = 0; j < i; j++) {
			y *= 31;
			y %= 1234567891;
		}
		h +=(( (x+1)%1234567891) *y)%1234567891;

	}
	cout << h%1234567891;
	return 0;
}