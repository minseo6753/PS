#include<iostream>
#include<queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	priority_queue<pair<int, int>>a;
	for (int i = 0; i < n; i++) {
		int ans;
		cin >> ans;
		a.push({ ans,-i });
	}
	
	int m;
	cin >> m;
	priority_queue<pair<int, int>>b;
	for (int i = 0; i < m; i++) {
		int ans;
		cin >> ans;
		b.push({ ans,-i });
	}

	int arr[100];
	int size = 0;
	int apo = -1;
	int bpo = -1;
	while (!a.empty()&&!b.empty()) {
		
		if (a.top().first > b.top().first)a.pop();
		else if (a.top().first < b.top().first)b.pop();
		else {
			if (-a.top().second < apo)a.pop();
			else if (-b.top().second < bpo)b.pop();
			else {
				arr[size++] = a.top().first;
				apo = -a.top().second;
				bpo = -b.top().second;
				a.pop();
				b.pop();
			}
		}
	}

	cout << size << '\n';
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
}