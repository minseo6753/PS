#include<iostream>
#include <algorithm>
#include<string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	
	if (s[0] == ' ') s.erase(s.begin());
	if (s.size() == 0) {
		cout << 0;
		return 0;
	}
	if (s[s.size() - 1] == ' ') s.erase(--s.end());
	int n = s.size();

	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	n -= s.size();
	cout << n + 1;
}