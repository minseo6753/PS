#include<iostream>
using namespace std;

int arr[100000];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] > max)max = arr[i];
	}

	int st = max;
	int end = sum;
	while (st < end) {
		int mid = (st + end) / 2;
		
		int cnt = 1;
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			if (tmp + arr[i] > mid) {
				cnt++;
				tmp = arr[i];
			}
			else tmp += arr[i];
		}
		
		if (cnt <= m)end = mid;
		else st = mid + 1;
	}

	cout << end;
}