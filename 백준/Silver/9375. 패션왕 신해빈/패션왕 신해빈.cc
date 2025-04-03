#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		unordered_map<string, int>m;
		for (int j = 0; j < n; j++) {
			string name, type;
			cin >> name >> type;
			if (m.count(type))m[type]++;
			else m[type] = 1;
		}
		int sum = 1;
		for (auto e:m) {
			sum *= e.second + 1;
		}
		cout << sum - 1 << '\n';
	}
}