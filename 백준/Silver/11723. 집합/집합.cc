#include<iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;
	
	bool arr[21] = {};

	for (int i = 0; i < m; i++) {
		string inst;
		cin >> inst;

		if (inst == "all") {
			for (int i = 1; i <= 20; i++)arr[i] = 1;
		}
		else if (inst == "empty") {
			for (int i = 1; i <= 20; i++)arr[i] = 0;
		}
		else {
			int x;
			cin >> x;

			if (inst == "add")arr[x] = 1;
			else if (inst == "remove")arr[x] = 0;
			else if (inst == "check")cout << arr[x] << '\n';
			else if (inst == "toggle") arr[x] = !arr[x];
		}
	}
}