#include<iostream>
#include<vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* arr = new int[n+1];
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	vector<char>v;

	bool* pop = new bool[n + 1]();


	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] > arr[i - 1]) {
			while (num < arr[i]) {
				num++;
				v.push_back('+');
			}
			
		}
		else {
			for (int j = arr[i] + 1; j < arr[i - 1]; j++) {
				if (!pop[j]) {
					cout << "NO";
					return 0;
				}
			}
		}

		v.push_back('-');
		pop[arr[i]] = true;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}