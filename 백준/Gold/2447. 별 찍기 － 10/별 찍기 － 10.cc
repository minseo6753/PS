#include<iostream>	
#include<vector>
using namespace std;

void star(vector<vector<char>>& v, int row, int col, int n) {
	
	if (n == 1) {
		v[row][col] = '*';
		return;
	}
	
	for (int i = 0; i < n; i += n / 3) {
		for (int j = 0; j < n; j += n / 3) {
			if (i == n / 3 && j == n / 3)continue;
			star(v, row + i, col + j, n / 3);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n;
	cin >> n;
	vector<vector<char>>v(n, vector<char>(n,' '));
	
	star(v, 0, 0, n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j];
		}
		cout << '\n';
	}
}