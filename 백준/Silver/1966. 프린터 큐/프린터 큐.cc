#include<iostream>
#include<queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		
		queue<pair<int,bool>>q;
		priority_queue<int>max;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (j == m)q.push(make_pair(a, 1));
			else q.push(make_pair(a,0));
			max.push(a);
		}
		int cnt = 0;
		while (true) {
			while (q.front().first != max.top()) {
				q.push(q.front());
				q.pop();
			}
			if (q.front().second) {
				cout << cnt + 1 << '\n';
				break;
			}
			q.pop();
			max.pop();
			cnt++;
		}

	}
}