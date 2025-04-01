#include<iostream>
using namespace std;

int main() {
	long long x;
	cin >> x;
	if (x % 3 == 1)cout << 'U';
	else if (x % 3 == 2)cout << 'O';
	else cout << 'S';
}