#include<iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int t = m * 1440 / n;
	if (t / 60 < 10)cout << 0;
	cout << t / 60 << ':';
	if (t % 60 < 10)cout << 0;
	cout << t % 60;
}