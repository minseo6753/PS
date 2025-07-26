#include<iostream>
#include<cstring>
using namespace std;

char arr[3072][6143];

void star(int row, int col, int n) {
	
	if (n == 3) {
		arr[row][col] = '*';
		arr[row + 1][col - 1] = '*';
		arr[row + 1][col + 1] = '*';
		arr[row + 2][col - 2] = '*';
		arr[row + 2][col - 1] = '*';
		arr[row + 2][col] = '*';
		arr[row + 2][col + 1] = '*';
		arr[row + 2][col + 2] = '*';
		return;
	}

	star(row, col, n / 2);
	star(row + n / 2, col - n / 2, n / 2);
	star(row + n / 2, col + n / 2, n / 2);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	memset(arr, ' ', sizeof(arr));

	star(0, n-1, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}