#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>>arr;
	for (int i = 0; i < n; i++) {

		int x, y;
		cin >> x >> y;
		arr.push_back(make_pair(x, y));

	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		cout << arr[i].first <<' '<< arr[i].second << '\n';
	}
}