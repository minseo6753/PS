#include<iostream>
#include<algorithm>
using namespace std;

bool compare( pair<int, string> a, pair<int, string> b) {
	
	return a.first < b.first;
}

int main() {
	int n;
	cin >> n;

	pair<int, string>* arr = new pair<int, string>[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	stable_sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i].first << ' ' << arr[i].second << endl;
	}
}