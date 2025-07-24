#include<iostream>
#include<vector>
using namespace std;

int mov[4] = { 1,-1,0,0 };

int dfs(int row, int col, const vector<string>& board, vector<bool>& visit,int cnt) {
	
	int maxi = cnt;
	for (int i = 0; i < 4; i++) {

		int tr = row + mov[i];
		int tc = col + mov[3 - i];

		if (tr >= 0 && tr < board.size() && tc >= 0 && tc < board[0].size()) {

			int alp = board[tr][tc] - 65;

			if (!visit[alp]) {
				visit[alp] = true;
				maxi = max(maxi, dfs(tr, tc, board, visit,cnt+1));
				visit[alp] = false;
			}
		} 
	}
	return maxi;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	cin >> r >> c;
	vector<string>board(r);
	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}
	vector<bool>visit(26, false);
	visit[board[0][0] - 65] = true;
	cout << dfs(0, 0, board, visit,1);
}