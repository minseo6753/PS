#include<iostream>
#include<vector>

using namespace std;

vector<int>v(100000, 0);

void facto(int a,int b) {
	int k = a;
	for (int i = 2; i * i <= k; i ++) {

		
		while (a % i == 0) {
			a /= i;
			v[i] += b;
		}
		
	}
	if (a > 1) {
		v[a] += b;
	}
	
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int a;
	cin >> a;
	facto(abs(a), 1);

	bool zero = false;
	for (int i = 0; i < n - 1; i++) {

		char op;
		cin >> op;

		if (op == '*') {
			cin >> a;
			facto(abs(a), 1);
			if (a == 0) {
				zero = true;
			}
		}
		else if (op == '/') {
			cin >> a;
			facto(abs(a), -1);
		}
	}
	
	if (zero) {
		cout << "mint chocolate";
		return 0;
	}

	for (int i = 2; i < 100000; i++){
		if (v[i] < 0) {
			cout << "toothpaste";
			return 0;
		}
	}

	cout << "mint chocolate";

}