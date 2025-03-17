#include<iostream>
#include<string>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	string s = to_string(a * b * c);
	int arr[10] = { 0 };
	for (int i = 0; i < s.size(); i++) {
		arr[s[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
}