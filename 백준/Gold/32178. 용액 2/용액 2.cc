#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<long long,int>>v(n+1);
	v[0] = make_pair(0, 0);
	
	for (int i = 1; i <= n; i++) {
		long long a;
		cin >> a;
		v[i].first = v[i - 1].first + a;
		v[i].second = i;
	}
	sort(v.begin(), v.end());

	long long gap = 2000000000;
	int l,r;
	for (int i = 0; i < n; i++) {
		if (abs(v[i + 1].first - v[i].first) < gap) {
			gap = v[i + 1].first - v[i].first;
			l = v[i].second;
			r = v[i + 1].second;
		}
	}
	if (l > r) {
		cout << -1 * gap << '\n';
		cout << r+1 << ' ' << l;
	}
	else {
		cout << gap << '\n';
		cout << l + 1 << ' ' << r;
	}
	
}