#include<iostream>
#include<stack>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	string boom;
	cin >> str >> boom;

	string result = "";
	for (int i = 0; i < str.size(); i++) {
		result += str[i];
		if (result[result.size()-1] == boom[boom.size() - 1] && result.size() >= boom.size()) {
			bool equal = true;
			for (int j = result.size() - boom.size(), k = 0; k < boom.size(); j++, k++) {
				if (result[j] != boom[k]) {
					equal = false;
					break;
				}
			}
			if (equal) {
				result.erase(result.size() - boom.size(), boom.size());
				
			}
			
		}
		
	}

	if (result == "")cout << "FRULA";
	else cout << result;
}