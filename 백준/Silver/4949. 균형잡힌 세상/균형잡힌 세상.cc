#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string s;
	getline(cin, s, '.');
	while (s.length()) {
		stack<char>st;
		bool prnt = false;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[')st.push(s[i]);
			else if (s[i] == ')') {
				if (st.empty() || st.top() != '(') {
					cout << "no" << '\n'; 
					prnt = true;
					break;
				}
				else st.pop();
				
			}
			else if (s[i] == ']') {
				if (st.empty() || st.top() != '[') {
					cout << "no" << '\n'; 
					prnt = true;
					break;
				}
				else st.pop();
				
			}
		}
		
		if (!prnt) {
			if (st.empty()) cout << "yes" << '\n';
			else cout << "no" << '\n';
		}

		cin.ignore();
		getline(cin, s, '.');
	}
}