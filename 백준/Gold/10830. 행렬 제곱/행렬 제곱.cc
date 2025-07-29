#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> mul(vector<vector<int>>& m1, vector<vector<int>>& m2) {
	
	vector<vector<int>>result(m1.size(), vector<int>(m1.size(),0));

	for (int i = 0; i < m1.size(); i++) {
		for (int j = 0; j < m2.size(); j++) {
			for (int k = 0; k < m1.size(); k++) {
				result[i][j] += (m1[i][k] * m2[k][j]) % 1000;
			}
		}
	}

	return result;
}

vector<vector<int>> fastPow(vector<vector<int>>& matrix, long long exp) {

	if (exp == 1)return matrix;

	vector<vector<int>>tmp = fastPow(matrix, exp / 2);
	tmp=mul(tmp, tmp);
	if (exp & 1)tmp=mul(tmp, matrix);
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long b;
	cin >> n >> b;

	vector<vector<int>>matrix(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	matrix=fastPow(matrix, b);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j]%1000 << ' ';
		}
		cout << '\n';
	}
}