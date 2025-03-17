#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[10000] = {0};
	int p = 0;
	for (int i=0;i<n;i++) {
		string s;
		cin >> s;
		
		if (s == "push") {
			int x;
			cin >> x;
			arr[p] = x;
			p += 1;
		}
		else if (s == "pop") {
			if (p == 0) {
				cout << -1<<endl;
			}
			else {
				cout << arr[p-1]<<endl;
				arr[p-1] = 0;
				p -= 1;
			}
			
		}
		else if (s == "size") {
			cout << p << endl;
		}
		else if (s == "empty") {
			if (p == 0) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (s == "top") {
			if (p == 0) {
				cout << -1 << endl;
			}
			else {
				cout << arr[p-1] << endl;
			}
			
		}
	}
}