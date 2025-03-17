#include<iostream>
using namespace std;

int Pow(int a, int b) {
	int result = 1;
	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
}

int main() {
	int b;
	string n;
	cin >> n >> b;
	
	int sum = 0;
	for (int exp = 0; exp < n.size(); exp++) {
		int index = n.size() - exp - 1;
		if (n[index] - 'A' >= 0) {
			sum += (n[index] - 'A' + 10) * Pow(b, exp);
		}
		else {
			sum += (n[index] - '0') * Pow(b, exp);
		}
	}
	cout << sum;
}