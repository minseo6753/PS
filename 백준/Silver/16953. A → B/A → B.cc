#include<iostream>
#include<queue>
using namespace std;

int bfs(int a, int b) {

	queue < pair<long long, int >> q;

	q.push({ a,0 });

	while (!q.empty()) {
		long long tmp = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (tmp == b) {
			return cnt + 1;
		}

		if (tmp * 2 <= b)q.push({ tmp * 2,cnt + 1 });
		if (tmp * 10 + 1 <= b)q.push({ tmp * 10 + 1,cnt + 1 });
	}
	return -1;
}

int main() {
	int a, b;
	cin >> a >> b;

	cout << bfs(a, b);
}