#include<iostream>
#include<queue>
using namespace std;

int mov[4] = { 1,-1,0,0 };

int bfs(int i, int j,string*arr,int n) {
	queue<pair<int, int>>q;
	q.push({ i,j });
	arr[i][j] = '0';

	int num = 1;
	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + mov[k];
			int ty = y + mov[3 - k];

			if (tx >= 0 && tx < n && ty >= 0 && ty < n && arr[tx][ty] == '1') {
				q.push({ tx,ty });
				arr[tx][ty] = '0';
				num++;
			}
		}
	}

	return num;
}

int main() {
	int n;
	cin >> n;
	string* arr = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	priority_queue<int,vector<int>,greater<int>>pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '1')pq.push(bfs(i, j, arr, n));
		}
	}
	cout << pq.size() << '\n';
	while (pq.size()) {
		cout << pq.top() << '\n';
		pq.pop();
	}
}