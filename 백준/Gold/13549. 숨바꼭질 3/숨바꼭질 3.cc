#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct node {
	int posi;
	int time;
};

struct cmp {
	bool operator()(node a, node b) {
		return a.time > b.time;
	}
};

int bfs(int n, int k) {
	priority_queue<node,vector<node>,cmp>q;
	vector<bool>visit(200001 , false);
	q.push({n,0});
	
	while (!q.empty()) {
		int tmp = q.top().posi;
		int time = q.top().time;
		q.pop();
		visit[tmp] = true;

		if (tmp == k)return time;

		if (tmp < k && !visit[tmp * 2]) {
			q.push({ tmp * 2,time });
			
		}
		if (tmp >= 1 && !visit[tmp - 1]) {
			q.push({ tmp - 1,time + 1 });
			
		}
		if (tmp < k * 2 && !visit[tmp + 1]) {
			q.push({ tmp + 1,time + 1 });
			
		}

	}
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << bfs(n, k);
}