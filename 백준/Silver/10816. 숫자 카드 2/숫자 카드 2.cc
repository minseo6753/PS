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

	int* arr = new int[n];
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int p = 0;
	while (p != n) {
		int cnt = 1;
		int q = p;
		while (q < n-1 && arr[q] == arr[q + 1]) {
			
			q++;
			cnt++;
		}
		v.push_back(make_pair(arr[p], cnt));
		p = q + 1;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tem;
		cin >> tem;

		int st = 0;
		int end = v.size() - 1;
		int mid;
		while (st <= end) {
			mid = (st + end) / 2;
			if (v[mid].first == tem) {
				
				break;
			}
			else if (v[mid].first > tem) {
				end = mid-1;
			}
			else st = mid+1;
		}

		if (st <= end)cout << v[mid].second << ' ';
		else cout << 0 << ' ';
	}
}