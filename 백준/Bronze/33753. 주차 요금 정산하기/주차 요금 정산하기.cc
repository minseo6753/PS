#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int t;
	cin >> t;
	if (t <= 30)cout << a;
	else cout << a + int(ceil(double(t-30) / b)) * c;
}