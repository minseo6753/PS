#include<iostream>
#include<queue>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	queue<int>qu;

	for (int i = 1; i <= n; i++) {
		qu.push(i);
	}


	cout << '<';
	while (qu.size()>1) {
		for (int i = 0; i < k-1; i++) {
			qu.push(qu.front());
			qu.pop();
		}
		cout << qu.front() << ", ";
		qu.pop();
	}
	cout << qu.front() << '>';
}