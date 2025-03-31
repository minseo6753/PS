#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string>map;
	for (int i = 0; i < n; i++) {
		string k, v;
		cin >> k >> v;
		map[k] = v;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		cout << map[s] << '\n';
	}
}