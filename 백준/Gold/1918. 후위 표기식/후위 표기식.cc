#include<iostream>
#include<stack>
using namespace std;

int prio(char op) {
	if (op == '+' || op == '-')return 1;
	if (op == '*' || op == '/')return 2;
	if (op == '(')return 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string exp;
	cin >> exp;

	stack<char>s;
	for (int i = 0; i < exp.size(); i++) {
		if ('A' <= exp[i] && exp[i] <= 'Z') {
			cout << exp[i];
		}
		else {
			if (exp[i] == ')') {
				while (s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				s.pop();
			}
			else if (s.empty()||s.top()=='('||exp[i]=='(')s.push(exp[i]);
			else {
				while (!s.empty() && prio(s.top()) >= prio(exp[i])) {
					cout << s.top();
					s.pop();
				}
				s.push(exp[i]);
			}
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}