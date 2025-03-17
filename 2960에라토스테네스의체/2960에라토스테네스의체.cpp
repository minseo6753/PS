#include<iostream>
#include<vector>

using namespace std;

int prime(int n,int k) {

	vector < bool > v(n + 1, true);
	int cnt = 0;
	for (int i = 2; i <= n; i++) {

		if (v[i]) {
			int p = i;
			
			for (int j = 1; j * p <= n; j++) {

				if (v[j * p]) {

					v[j * p] = false;

					cnt++;
					if (cnt == k) {
						return j * p;
					}
				}
			}
		}
	}
}

int main() {

	int n, k;
	cin >> n >> k;

	cout<<prime(n, k);
}