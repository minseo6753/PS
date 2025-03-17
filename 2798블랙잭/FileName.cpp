#include<iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int arr[100];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int p = j + 1; p < n; p++) {
				int sum = arr[i] + arr[j] + arr[p];
				if (sum > result && sum <= m) {
					result = sum;
				}
			}
		}
	}
	cout << result;
}