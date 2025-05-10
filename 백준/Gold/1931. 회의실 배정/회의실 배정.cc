#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second)return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>>v(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}
	sort(v.begin(), v.end(), compare);
	
	int end = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].first >= end) {
			cnt++;
			end = v[i].second;
		}
	}
	cout << cnt;
}