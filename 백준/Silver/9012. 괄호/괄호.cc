#include<iostream>
#include<stack>

using namespace std;

int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {

		string ps;
		cin >> ps;

		stack<char>st;
		
		for (int j = 0; j < ps.length(); j++) {
			if (ps[j] == ')') {
				if (st.empty()) {
					st.push(')');
					break;
				}
				st.pop();
			}
			else {
				st.push('(');
			}
		}

		if (st.empty()) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
}