#include<iostream>
#include<vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;
	vector<int>v(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum ^= v[i];
	}
	int max = sum;
	for (int i = 0; i < n; i++) {
		int t = sum ^ v[i];
		if (t > max)max = t;
	}
	cout << max << max;
}