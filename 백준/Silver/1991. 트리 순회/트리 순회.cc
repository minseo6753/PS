#include<iostream>
using namespace std;

int arr[26][2];

void preorder(int i, int n) {
	if (i == n - 1) {
		cout << char(i+65);
		return;
	}
	if (i >= 0) {
		cout << char(i+65);
		preorder(arr[i][0], n);
		preorder(arr[i][1], n);
	}
}

void inorder(int i, int n) {
	if (i == n - 1) {
		cout << char(i + 65);
		return;
	}
	if (i >= 0) {
		inorder(arr[i][0], n);
		cout << char(i + 65);
		inorder(arr[i][1], n);
	}
}

void postorder(int i, int n) {
	if (i == n - 1) {
		cout << char(i + 65);
		return;
	}
	if (i >= 0) {
		postorder(arr[i][0], n);
		postorder(arr[i][1], n);
		cout << char(i + 65);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char p, lc, rc;
		cin >> p >> lc >> rc;
		arr[p - 65][0] = lc - 65;
		arr[p - 65][1] = rc - 65;
	}

	preorder(0, n);
	cout << '\n';
	inorder(0, n);
	cout << '\n';
	postorder(0, n);
}