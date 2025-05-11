#include<iostream>	
#include<vector>
#include<queue>
#include<array>
using namespace std;

int bfs(vector<vector<vector<int>>>& v, int h,int n,int m,queue<array<int,4>>&q,int zero) {
	
	int hmov[6] = { 1,-1,0,0,0,0 };
	int nmov[6] = { 0,0,1,-1,0,0 };
	int mmov[6] = { 0,0,0,0,1,-1 };

	int day;
	int zerotoone = 0;
	while (!q.empty()) {
		auto tmp = q.front();
		int i = tmp[0];
		int j = tmp[1];
		int k = tmp[2];
		day = tmp[3];
		q.pop();
		
		for (int p = 0; p < 6; p++) {
			int ti = i + hmov[p];
			int tj = j + nmov[p];
			int tk = k + mmov[p];
			if (ti >= 0 && ti < h && tj >= 0 && tj < n && tk >= 0 && tk < m && v[ti][tj][tk] == 0) {
				q.push({ ti,tj,tk,day+1 });
				v[ti][tj][tk] = 1;
				zerotoone++;
			}
		}
	}

	if (zerotoone < zero)return -1;
	else return day;
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n, h;
	cin >> m >> n >> h;

	vector<vector<vector<int>>>v(h, vector<vector<int>>(n, vector<int>(m)));
	queue<array<int,4>>q;
	int zero = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int a;
				cin >> a;
				v[i][j][k] = a;
				if (a == 1)q.push({ i,j,k,0 });
				else if (a == 0)zero++;
			}
		}
	}

	if (zero == 0)cout << 0;
	else cout << bfs(v, h, n, m, q, zero);

}