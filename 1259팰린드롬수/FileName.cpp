#include<iostream>
using namespace std;

int main() {
	string n;
	cin >> n;
	while (n!="0") {
		int i, j;
		for (i = 0, j = n.size() - 1; i < j; i++, j--) {
			if (n[i] != n[j]) {
				break;
			}
		}
		if (i < j)cout << "no";
		else cout << "yes";
		cout << endl;

		cin >> n;
	}
}