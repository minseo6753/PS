#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> hashTable;
    vector<string> num(n + 1);

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        num[i] = s;
        hashTable[s] = i;  // O(1) 삽입
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (isdigit(s[0])) cout << num[stoi(s)] << '\n';  // O(1)
        else cout << hashTable[s] << '\n';  // O(1)
    }
}