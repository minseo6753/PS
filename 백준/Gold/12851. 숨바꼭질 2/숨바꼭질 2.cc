#include<iostream>
#include<queue>
using namespace std;

bool visit[100001] = { 0 };

void bfs(int n, int k) {
	queue<int>q;
	q.push(n);

	int rtime;
	int rout = 0;

	int time = 0;
	while (!q.empty()) {
		int loop = q.size();
		while (loop --) {
			int num = q.front();
			q.pop();
			visit[num] = true;

			if (num == k) {
				rtime = time;
				rout++;
				continue;
			}

			if (num * 2 <= 100000 && !visit[num * 2]) {
				q.push( num * 2);
			}
			if (num + 1 <= 100000 && !visit[num + 1]) {
				q.push(num + 1);
			}
			if (num - 1 >= 0 && !visit[num - 1]) {
				q.push(num - 1);
			}
		}
		if (rout > 0)break;
		time++;
	}
	
	cout << rtime << '\n'<<rout;
}

int main() {
	int n, k;
	cin >> n >> k;

	bfs(n, k);
}