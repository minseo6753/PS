#include<iostream>

using namespace std;

int main() {
	int k, n;
	cin >> k >> n;

	int* arr = new int[k];
	int max = 0;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		if (arr[i] > max)max = arr[i];
	}
	
	int st = 1;
	int end = max;
	while (true) {
		
		int mid = ((long long)st + end) / 2 ;

		long long sum = 0;
		for (int i = 0; i < k; i++) {
			sum += arr[i] / mid;
		}

		if (sum >= n) {
			st = mid;
			if (st + 1 >= end)break;
		}
		else end = mid - 1;
	}

	long long sum = 0;
	for (int i = 0; i < k; i++) {
		sum += arr[i] / end;
	}
	if (sum >= n)cout << end;
	else cout << st;
}