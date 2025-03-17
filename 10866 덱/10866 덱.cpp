#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[10000] = { 0 };
	int p = 0;
	int q = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "push_front") {
			int x;
			cin >> x;
			arr[q] = x;
			q += 1;
		}
		else if (s == "pop") {
			if (p >= q) {
				cout << -1 << endl;
			}
			else {
				cout << arr[p] << endl;
				arr[p] = 0;
				p += 1;
			}

		}
		else if (s == "size") {
			cout << q - p << endl;
		}
		else if (s == "empty") {
			if (p >= q) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (s == "front") {
			if (p >= q) {
				cout << -1 << endl;
			}
			else {
				cout << arr[p] << endl;
			}

		}
		else if (s == "back") {
			if (p >= q) {
				cout << -1 << endl;
			}
			else {
				cout << arr[q - 1] << endl;
			}

		}
	}
}