#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int arr[10] = { 0 };
int temp[9];
bool used[9] = { 0 };

void dfs(int i, int size) {

	temp[size] = arr[i];

	if (size == m) {
		
		for (int j = 1; j <= m; j++) {
			cout << temp[j] << ' ';
		}
		cout << '\n';
		return;
	}

	int pre=0;
	for (int j = 1; j <= n; j++) {

		if (!used[j]&&arr[j]!=pre) {
			used[j] = true;
			dfs(j, size + 1);
			used[j] = false;
			pre = arr[j];
		}

	}
	
}

int main() {
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	

	sort(arr+1,arr+n+1);

	dfs(0, 0);
}