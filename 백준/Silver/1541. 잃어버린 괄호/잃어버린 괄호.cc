#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main() {
	string ex;
	cin >> ex;
	int i = 0;
	vector<string> postfix;
	stack<string>s;
	while (i < ex.size()) {
		if (ex[i] == '+')s.push("+");
		else if (ex[i] == '-') {
			while (s.size()) {
				postfix.push_back(s.top());
				s.pop();
			}
			s.push("-");
		}
		else {
			string num;
			while (isdigit(ex[i])) {
				num.push_back(ex[i]);
				i++;
				if (i == ex.size())break;
			}
			i--;
			postfix.push_back(num);
		}
		i++;
	}
	while (s.size()) {
		postfix.push_back(s.top());
		s.pop();
	}

	i = 0;
	while (i < postfix.size()) {
		if (postfix[i] == "+") {
			int temp = stoi(s.top());
			s.pop();
			temp += stoi(s.top());
			s.pop();
			s.push(to_string(temp));
		}
		else if (postfix[i] == "-") {
			int temp = stoi(s.top());
			s.pop();
			temp = stoi(s.top()) - temp;
			s.pop();
			s.push(to_string(temp));
		}
		else {
			s.push(postfix[i]);
		}
		i++;
	}
	cout << s.top();
}