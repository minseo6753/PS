#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int b;
		cin >> b;

		int p = 0;
		int q = n - 1;
		
		while (p <= q) {
			int mid = (p + q) / 2;
			if (a[mid] == b)break;
			if (a[mid] < b) {
				p = mid + 1;
			}
			else {
				q = mid - 1;
			}
		}
		if (p <= q)cout << 1;
		else cout << 0;
		cout << '\n';
	}
}