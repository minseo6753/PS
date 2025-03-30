#include<iostream>	
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	set<string>s;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		s.insert(a);
	}
	vector<string>v;
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		if (s.find(a)!=s.end()) {
			v.push_back(a);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size();
	for (int i = 0; i < v.size(); i++) {
		cout << '\n' <<  v[i];
	}
}