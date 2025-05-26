#include<iostream>
#include<vector>
#include<queue>
using namespace std;

string bfs(int a, int b) {
	queue<pair<int, string>>q;
	vector<bool>visit(10000, 0);

	visit[a] = 1;

	q.push({ a, "" });
	
	while (!q.empty()) {
	
		int n = q.front().first;
		string s = q.front().second;
		q.pop();
		if (n == b)return s;

		int tn = (n * 2) % 10000;
		if (!visit[tn]) {
			q.push({ tn, s + "D" });
			visit[tn] = 1;
		}
		
		if (n == 0)tn = 9999;
		else tn = n - 1;
		if (!visit[tn]) {
			q.push({ tn, s + "S" });
			visit[tn] = 1;
		}		

		tn = (n % 1000) * 10 + n / 1000;
		if (!visit[tn]) {
			q.push({ tn,s + "L" });
			visit[tn] = 1;
		}
		
		tn = (n % 10) * 1000 + n / 10;
		if (!visit[tn]) {
			q.push({ tn,s + "R" });
			visit[tn] = 1;
		}
		
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		cout << bfs(a, b) << '\n';
	}
}