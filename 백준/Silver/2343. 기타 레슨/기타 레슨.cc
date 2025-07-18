#include<iostream>
#include<vector>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int>v(n);
	int l = 0;
	int mx = 0;
	for (int i = 0; i < n; i++) {

		cin >> v[i];
		l += v[i];
		mx = max(mx, v[i]);

	}

	int low = mx;
	int high = l;
	while (low < high) {

		int mid = (low + high) / 2;

		int s = 0;
		int k = 0;
		for (int i = 0; i < n; i++) {

			s += v[i];
			if (s > mid) {
				k++;
				s = v[i];
			}

		}
		k++;

		if (k <= m) {
			high = mid;
		}
		else {
			low = mid+1;
		}
	}
	cout << high;
}