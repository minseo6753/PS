#include<iostream>
#include<vector>
#include<map>	

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	vector<int>v(n);
	map<int, int>m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		m[v[i]] = 0;
	}
	int rank = 0;
	for (auto& i : m) {
		i.second = rank;
		rank++;
	}
	for (int i = 0; i < n; i++) {
		cout << m.find(v[i])->second << ' ';
	}
}