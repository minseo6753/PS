#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int paintsum = 64;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			//첫번째 칸 B로
			int paint = 0;
			char color = 'B';
			for (int p = i; p < i + 8; p++) {
				for (int q = j; q < j + 8; q++) {
					if (v[p][q] != color)paint++;

					if (color == 'B')color = 'W';
					else color = 'B';
				}
				if (color == 'B')color = 'W';
				else color = 'B';
			}
			if (paint < paintsum)paintsum = paint;

			//첫번째 칸 W로
			paint = 0;
			color = 'W';
			for (int p = i; p < i + 8; p++) {
				for (int q = j; q < j + 8; q++) {
					if (v[p][q] != color)paint++;

					if (color == 'B')color = 'W';
					else color = 'B';
				}
				if (color == 'B')color = 'W';
				else color = 'B';
			}
			if (paint < paintsum)paintsum = paint;
		}
	}
	cout << paintsum;
}