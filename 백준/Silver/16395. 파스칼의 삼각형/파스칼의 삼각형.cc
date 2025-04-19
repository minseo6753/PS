#include<iostream>	
#include<map>
using namespace std;

map<pair<int,int>, int>memo;

int C(int n, int k) {
	if (k == 1 || k == n)return 1;
	if (memo.find(make_pair(n, k)) != memo.end())return memo[make_pair(n, k)];
	else {
		memo[make_pair(n, k)] = C(n - 1, k - 1) + C(n - 1, k);
		return memo[make_pair(n, k)];
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << C(n, k );
}