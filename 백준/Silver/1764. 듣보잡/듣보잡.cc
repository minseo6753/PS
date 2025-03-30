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

	vector<string>v2(m);
	for (int i = 0; i < m; i++) {
		cin >> v2[i];
	}
	sort(v2.begin(), v2.end());

	
	vector<string>v3;
	int st = 0;
	int end = n - 1;
	int i=0;
	while(st<=end&&i<m) {
		
		int mid= (st + end) / 2;
		while (st <= end) {
			mid = (st + end) / 2;
			if (v[mid] == v2[i]) {
				v3.push_back(v2[i]);
				mid++;
				break;
			}
			if (v[mid] < v2[i]) {
				st = mid + 1;
			}
			else end = mid - 1;
		}
		st = mid;
		end = n - 1;
		i++;
	}
	
	cout << v3.size();
	for (int i = 0; i < v3.size(); i++) {
		cout << '\n' << v3[i];
	}
}