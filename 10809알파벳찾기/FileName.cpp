#include<iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int arr[26];
	for (int i = 0; i < 26; i++) {
		arr[i] = -1;
	}
	for (int i = 0; i < s.size(); i++) {
		int alp = s[i] - 'a';
		if (arr[alp] == -1) arr[alp] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << ' ';
	}
}