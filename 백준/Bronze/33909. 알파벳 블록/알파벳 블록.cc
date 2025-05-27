#include<iostream>
using namespace std;

int main() {
	int s, c, o, n;
	cin >> s >> c >> o >> n;
	s += n;
	n = 0;
	c += o * 2;
	o = 0;

	int snum = s / 3;
	int cnum = c / 6;
	cout << min(snum, cnum);
}