#include<iostream>

using namespace std;

int arr[9];
int n, m;

void f(int a,int size) {

	arr[size] = a;

	if (size == m) {
		for (int i = 1; i <= m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	
	for (int j=a+1; j<= n-m+size+1; j++) {
		f(j, size + 1);
	}
}

int main() {

	cin >> n >> m;
	
	for (int i = 1; i <= n-m+1; i++) {
		f(i,1);
	}
}