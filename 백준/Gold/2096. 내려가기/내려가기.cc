#include<iostream>


using namespace std;

int min(int a, int b) {
	return (a < b) ? a : b;
}
int max(int a, int b) {
	return (a > b) ? a : b;
}

char v[100000][3];
int arr[100000][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[i][j];
		}
	}

	
	for (int i = 0; i < 3; i++) {
		arr[0][i] = v[0][i]-48;
	}
	for (int i = 1; i < n; i++) {
		int max1 = max(arr[i - 1][0], arr[i - 1][1]);
		int max2 = max(arr[i - 1][1], arr[i - 1][2]);
		arr[i][0] = v[i][0] + max1-48;
		arr[i][1] = v[i][1] + max(max1, max2)-48;
		arr[i][2] = v[i][2] + max2-48;
	}
	cout << max(max(arr[n - 1][0], arr[n - 1][1]), arr[n - 1][2]);
	cout << ' ';

	for (int i = 0; i < 3; i++) {
		arr[0][i] = v[0][i]-48;
	}
	for (int i = 1; i < n; i++) {
		int min1 = min(arr[i - 1][0], arr[i - 1][1]);
		int min2 = min(arr[i - 1][1], arr[i - 1][2]);
		arr[i][0] = v[i][0] + min1-48;
		arr[i][1] = v[i][1] + min(min1, min2)-48;
		arr[i][2] = v[i][2] + min2-48;
	}
	cout << min(min(arr[n - 1][0], arr[n - 1][1]),arr[n - 1][2]);
}