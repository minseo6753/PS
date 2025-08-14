#include<iostream>
#include<vector>
using namespace std;

vector<int> operator+(vector<int>& v1,vector<int>&v2) {
	vector<int> result;

	int carry = 0;

	for (int i = 0; i < v1.size(); i++) {
		int sum = v1[i] + v2[i] + carry;
		carry = sum / 10;
		result.push_back(sum % 10);
	}

	for (int i = v1.size(); i < v2.size(); i++) {
		int sum = v2[i] + carry;
		carry = sum / 10;
		result.push_back(sum % 10);
	}

	if(carry)result.push_back(carry);

	return result;
}

int main() {
	int n;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}

	vector<int>a(1,0);
	vector<int>b(1,1);
	for (int i = 2; i <= n; i++) {
		vector<int> tmp = b;
		b = a + b;
		a = tmp;
	}
	
	for (int i = b.size()-1; i >= 0; i--) {
		cout << b[i];
	}
}