#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> mtrxmul(vector<vector<int>>m1, vector<vector<int>>m2) {
	
	vector<vector<int>>result(2, vector<int>(2,0));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				result[i][j] += ((long long)m1[i][k] * m2[k][j]) % 1000000007;
			}
			result[i][j] %= 1000000007;
		}
	}

	return result;
}

vector<vector<int>>a(2, vector<int>(2));

vector<vector<int>> mtrxexp(long long n) {

	if (n == 1) {
		return a;
	}

	vector<vector<int>>tmp = mtrxexp(n / 2);
	tmp = mtrxmul(tmp, tmp);
	if (n % 2)tmp=mtrxmul(tmp, a);
	return tmp;
}

int main() {

	a[0][0] = 1;
	a[0][1] = 1;
	a[1][0] = 1;
	a[1][1] = 0;

	long long n;
	cin >> n;

	vector<vector<int>>result = mtrxexp(n);
	cout << result[0][1];
}