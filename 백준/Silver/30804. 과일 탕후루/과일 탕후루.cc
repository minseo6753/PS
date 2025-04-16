#include<iostream>
#include<vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int p = 0;
	int q = 0;
	int max = 0;
	int a;
	while (q < n) {
		
		while (q < n&& v[q] == v[p])q++;

		if (q < n) {
			a = v[p];
			int b = v[q];
			while (q < n && (v[q] == a || v[q] == b))q++;
		}

		if (q - p > max)max = q - p;

		p = q - 1;
		a = v[p];
		while (p >= 0 && v[p] == a)p--;
		p++;
	}
	cout << max;
}