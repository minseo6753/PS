#include<iostream>
using namespace std;

int fastPow(int a, int b,int c) {

	if (b == 1) {
		return a;
	}

	long long tmp = fastPow(a, b / 2, c);
	long long result = (tmp * tmp)%c;

	if (b & 1) {
		return (result * a) % c;
	}
	else return result;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	cout << fastPow(a, b, c)%c;
}