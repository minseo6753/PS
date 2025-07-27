#include<iostream>

using namespace std;

int arr[10000];

void post(int start, int end) {

	if (start > end)return;

	int i;
	for (i = start + 1; i <= end; i++) {
		if (arr[i] > arr[start])break;
	}

	post(start + 1 , i - 1);
	post(i, end);
	cout << arr[start]<<'\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;

	int n = 0;
	while (cin >> a) {
		arr[n++] = a;
	}

	post(0, n-1);
}