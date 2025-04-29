#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;

int bfs(int n, int k) {
	queue<int>q;
	q.push(n);

	vector<bool>visit(100001, 0);

	int time = -1;
	int tmp=-1;
	int cnt = 1;
	while(tmp!=k) {
		time++;
		
		int j = cnt;
		cnt = 0;
		for (int i = 0; i < j; i++) {
			tmp = q.front();
			if (tmp == k )break;
			q.pop();
			if (tmp*2<=100000&&!visit[tmp * 2]) {
				q.push(tmp * 2);
				visit[tmp * 2] = 1;
				cnt++;
			}
			if (tmp+1<=100000&&!visit[tmp + 1]) {
				q.push(tmp + 1);
				visit[tmp + 1] = 1;
				cnt++;
			}
			if (tmp-1>=0&&!visit[tmp - 1]) {
				q.push(tmp - 1);
				visit[tmp - 1] = 1;
				cnt++;
			}
		}
		
	}

	return time;
}

int main() {
	int n, k;
	cin >> n >> k;

	if (n == k)cout << 0;
	else cout<<bfs(n, k);

}