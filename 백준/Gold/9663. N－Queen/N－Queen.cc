#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>v(15,0);
int cnt = 0;
void queen(int n,int i) {

	if (i == n)cnt++;

	for (int j = 0; j < n; j++) {
		int k;
		for (k = 0; k < i; k++) {
			if (j == v[k]||abs(j-v[k])==abs(i-k	))break;
		}
		if (k == i) {
			v[i] = j;
			queen(n, i + 1);
		}
	}
}

int main() {
	int n;
	cin >> n;

	queen(n, 0);

	cout << cnt;

	
}