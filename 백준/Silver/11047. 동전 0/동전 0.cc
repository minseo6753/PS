#include<iostream>	
#include<vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int>v(n);
	int j;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (k / v[i])j = i;
	}

	int sum = 0;
	while (k) {
		sum += k / v[j];
		k %= v[j];
		j--;
	}

	cout << sum;
}