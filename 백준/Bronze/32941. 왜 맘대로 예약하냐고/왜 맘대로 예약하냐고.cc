#include<iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, x;
	cin >> t >> x;
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		bool kb = 0;
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			if (a == x)kb = 1;
		}
		if (kb == 1) {
			cnt++;
			
		}
	}
	if (cnt < n)cout << "NO";
	else cout << "YES";
	
}