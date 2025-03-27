#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second)return a.first < b.first;
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* arr = new int[n];
	pair<int, int>mode[8001] = {};

	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];

		mode[arr[i] + 4000].first = arr[i];
		mode[arr[i] + 4000].second++;
	}

	if (round(sum / n) == 0)cout << 0 << '\n';
	else cout << round(sum / n) << '\n';

	sort(arr, arr + n);

	cout << arr[n / 2] << '\n';

	sort(mode, mode + 8001,compare);
	
	if (n > 1 && mode[1].second == mode[0].second)cout << mode[1].first << '\n';
	else cout << mode[0].first << '\n';

	cout << arr[n - 1] - arr[0];

}