#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = 1;
	int num = 666;
	while (cnt != n) {
		num++;
		int temp = num;
		int six = 0;
		while (temp) {
			if (temp % 10 == 6)six++;
			else six = 0;
			temp /= 10;
			if (six == 3)break;
		}
		if (six == 3)cnt++;
	}
	cout << num;
	
}