#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;

		int score = 0;
		int sum = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'O') {
				score++;
			}
			else score = 0;
			sum += score;
		}
		cout << sum << endl;
	}
}