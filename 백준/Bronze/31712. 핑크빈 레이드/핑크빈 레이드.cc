#include<iostream>
using namespace std;

int main() {
	int c1, c2, c3, d1, d2, d3;
	cin >> c1 >> d1 >> c2 >> d2 >> c3 >> d3;
	int h;
	cin >> h;

	int s = 0;
	h -= d1 + d2 + d3;
	while (h > 0) {
		s++;
		if (s % c1 == 0)h -= d1;
		if (s % c2 == 0)h -= d2;
		if (s % c3 == 0)h -= d3;
	}
	cout << s;
}