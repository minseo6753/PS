#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<string>num(n+1);
	vector<pair<string, int>>name(n+1);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		num[i] = s;
		name[i] = make_pair(s, i);
	}

	sort(name.begin(),name.end());

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (isdigit(s[0])) {
			cout << num[stoi(s)] << '\n';
		}
		else {
			int st = 1;
			int end = n;
			while (st <= end) {
				int mid = (st + end) / 2;
				if (name[mid].first == s) {
					cout << name[mid].second << '\n';
					break;
				}
				if (name[mid].first < s) {
					st = mid + 1;
				}
				else end = mid - 1;
			}
		}
	}
}