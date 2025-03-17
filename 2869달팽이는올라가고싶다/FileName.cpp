#include<iostream>
#include<cmath>
using namespace std;

int main() {
	double v, a, b;
	cin >> a >> b >> v;
	cout << fixed;
	cout.precision(0);
	cout << ceil((v - a) / (a - b)) + 1;
}