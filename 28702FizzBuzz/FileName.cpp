#include<iostream>
#include<string>
using namespace std;

int main() {


	for (int i = 1; i <= 3; i++) {
		string s;
		cin >> s;
		if (isdigit(s[0])) {
			int a = stoi(s) + 4 - i;
			if (a % 3 != 0 && a % 5 != 0) cout << a;
			if (a % 3 == 0)cout << "Fizz";
			if (a % 5 == 0)cout << "Buzz";
			break;
		}
	}
	
}