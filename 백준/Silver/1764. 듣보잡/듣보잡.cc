#include<iostream>	
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	vector<string>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	vector<string>v3;
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		int st = 0;
		int end = n - 1;
		while (st <= end) {

			int mid = (st + end) / 2;

			if (v[mid] == a) {
				v3.push_back(a);
				
				break;
			}
			if (v[mid] < a) {
				st = mid + 1;
			}
			else end = mid - 1;
			
	
		}
	}

	
	cout << v3.size();
	sort(v3.begin(), v3.end());
	for (int i = 0; i < v3.size(); i++) {
		cout << '\n' << v3[i];
	}
}