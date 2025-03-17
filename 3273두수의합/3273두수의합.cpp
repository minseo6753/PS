#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;
	
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		
		cin >> v[i];
		
	}
	sort(v.begin(), v.end());

	int x;
	cin >> x;

	int i = 0;
	int j = n-1;
	int cnt = 0;
	while (i < j) {

		if (v[i] + v[j] == x) {
			cnt++;
			i++;
		}
		else if (v[i] + v[j] > x) {
			j--;
		}
		else if (v[i] + v[j] < x) {
			i++;
		}

	}
	cout << cnt;
}