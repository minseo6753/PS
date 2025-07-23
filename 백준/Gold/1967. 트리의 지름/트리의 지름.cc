#include<iostream>
#include<vector>
using namespace std;

struct Child {
	int num;
	int weight;
};

struct Value {
	int maxi;
	int sum;
};

void cal(int num, vector<vector<Child>>& tree,vector<Value>&v) {

	int maxi1 = 0;
	int maxi2 = 0;
	for (int i = 0; i < tree[num].size(); i++) {
		
		int child = tree[num][i].num;
		int weight = tree[num][i].weight;

		
		cal(child, tree, v);
			
		if (maxi2 < v[child].maxi + weight) {
			if (maxi1 < v[child].maxi + weight) {
				maxi2 = maxi1;
				maxi1 = v[child].maxi + weight;
			}
			else maxi2 = v[child].maxi + weight;
		}
		

	}
	v[num].maxi = maxi1;
	v[num].sum = maxi1+maxi2;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<vector<Child>>tree(n + 1);
	for (int i = 0; i < n-1; i++) {
		int p, c, w;
		cin >> p >> c >> w;
		tree[p].push_back({ c,w });
		
	}

	vector<Value>v(n+1);

	cal(1, tree, v);

	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = max(result, v[i].sum);
	}
	cout << result;
}