#include<iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int b[10001] = { 0, };
	int k = 0;
	for (int i = 0; i < n; i++) {
		int ans;
		cin >> ans;
		b[ans]++;

		if (k < ans) {
			k = ans;
		}
	}
	

	for (int i = 0; i <= k; i++) {
		if (b[i]) {
			for (int j = 0; j < b[i]; j++) {
				cout << i << '\n';
			}
			
		}
	
	}
	

}