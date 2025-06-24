#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[9];
int temp[9];
bool visit[9] = { 0 };

void dfs(int i,int len) {
	temp[len] = arr[i];

	if (len == m) {
		for (int j = 1; j <= m; j++) {
			cout << temp[j] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int j = 1; j <= n; j++) {
		if (!visit[j]) {
			visit[j] = true;
			dfs(j, len + 1);
			visit[j] = false;
		}
		
	}
}

int main() {
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr+1, arr + n+1);
	dfs(0, 0);
}