#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	if (n == 1) {
		cout << v[0];
		return 0;
	}

	vector<pair<int,int>>p(n); //first는 1칸 second는 2칸
	p[n - 1] = { v[n - 1],v[n - 1] };
	p[n - 2] = { v[n - 2] + v[n - 1],0 };

	for (int i = n - 3; i >= 0;i--) {
		p[i].first = v[i] + p[i + 1].second;
		p[i].second = v[i] + max(p[i + 2].first, p[i + 2].second);
	}
	
	cout << max(max(p[0].first, p[0].second), max(p[1].first, p[1].second));
}