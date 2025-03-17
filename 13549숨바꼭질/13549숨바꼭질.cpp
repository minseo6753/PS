#define INF 987654321

#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int  main() {

	int n, k;

	cin >> n >> k;

	vector<int>arr(100001,INF);
	vector<bool>tf(100001, false);

	arr[n] = 0;

	deque<int>dq;

	dq.push_front(n);

	while (!tf[k]) {

		int i = dq.front();
		dq.pop_front();

		if (i * 2 > 100000) {
			continue;
		}
		if (!tf[i * 2]) {
			if (arr[i] < arr[i * 2]) {
				arr[i * 2] = arr[i];
			}
			dq.push_front(i * 2);
		}
		if (i+1 > 100000) {
			continue;
		}
		if (!tf[i + 1]) {
			if (arr[i] + 1 < arr[i + 1]) {
				arr[i + 1] = arr[i] + 1;
			}
			dq.push_back(i + 1);
		}
		if (i == 0) {
			continue;
		}
		if (!tf[i - 1]) {
			if (arr[i] + 1 < arr[i - 1]) {
				arr[i - 1] = arr[i] + 1;
			}
			dq.push_back(i - 1);
		}


		tf[i] = true;
	}
	cout << arr[k];
}