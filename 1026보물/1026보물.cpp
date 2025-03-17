#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>b;

bool compare(int x, int y) {
	return b[x] < b[y];
}

int main() {

	int n;
	cin >> n;

	vector<int>a;
	for (int i = 0; i < n; i++) {
		int an;
		cin >> an;
		a.push_back(an);
	}

	for (int i = 0; i < n; i++) {
		int bn;
		cin >> bn;
		b.push_back(bn);
	}

	vector<int>arr;
	for (int i = 0; i < n; i++) {
		
		arr.push_back(i);
	}
	sort(arr.begin(), arr.end(), compare);

	sort(a.begin(), a.end() , greater<>());

	vector<int>a2(n);
	for (int i = 0; i < n; i++) {
		a2[arr[i]] = a[i];
	}
	a = a2;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}

	cout << sum;

}