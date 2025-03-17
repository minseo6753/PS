#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int two = 0;
	int five = 0;
	for (int i = 2; i <= n; i++) {
		int temp = i;
		while (temp % 2 == 0) {
			two++;
			temp /= 2;
		}
		temp = i;
		while (temp % 5 == 0) {
			five++;
			temp /= 5;
		}
	}
	cout << min(two, five);
	
}