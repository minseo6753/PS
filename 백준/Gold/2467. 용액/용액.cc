#include<iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int arr[100000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int po1 = 0;
	int po2 = n - 1;
	int mini = 2000000000;
	int l,r;
	while (po1<po2) {

		int sum = arr[po1] + arr[po2];

		if (abs(sum) < mini) {
			mini = abs(sum);
			l = po1;
			r = po2;
		}

		if (sum < 0)po1++;
		else if (sum > 0)po2--;
		else break;
	}
	cout << arr[l] << ' ' << arr[r];
}