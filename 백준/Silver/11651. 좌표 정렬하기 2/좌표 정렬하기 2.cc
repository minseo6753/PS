#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	pair<int, int> arr[100000];

	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr, arr + n);
	for (int i= 0; i < n; i++) {
		cout << arr[i].second <<' '<< arr[i].first<<'\n';
	}
}