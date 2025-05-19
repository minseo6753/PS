#include<iostream>
#include<queue>
using namespace std;

pair<int,int> ls[30];
bool visit[101] = { 0 };

int bfs(int size) {
	queue<int>q;
	q.push(1);

	int step = 0;
	int lop = 1;
	while (true) {

		
		while (lop--) {
			int x = q.front();
			q.pop();
			if (x == 100)return step;
		
			for (int j = 1; j <= 6; j++) {

				int i;
				for (i = 0; i < size; i++) {
					if (x+j == ls[i].first) {
						q.push(ls[i].second);
						visit[x+j] = 1;
					
						break;
					}
				}
				
				if (i == size) {
					if (x + j <= 100&&!visit[x+j]) {
						q.push(x + j);
						visit[x + j] = 1;
						
					}
				}

			}
			
			
		}
		step++;
		lop = q.size();
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m + n; i++) {
		cin >> ls[i].first >> ls[i].second;
	}

	cout << bfs(m + n);
}