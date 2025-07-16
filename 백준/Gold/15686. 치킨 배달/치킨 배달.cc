#include<iostream>
#include<vector>
using namespace std;

int select(int i, vector<vector<int>>& dist, vector<int> minLi,int cnt, int m) {

	if (cnt == m || i==dist[0].size()) {
		int sum = 0;
		for (int j = 0; j < minLi.size(); j++) {
			sum += minLi[j];
		}
		return sum;
	}

	int notIncluded = select(i + 1, dist, minLi, cnt, m);

	bool changed = false;
	for (int j = 0; j < minLi.size(); j++) {
		if (dist[j][i] < minLi[j]) {
			minLi[j] = dist[j][i];
			changed = true;
		}
	}

	if (changed)return min(select(i + 1, dist, minLi, cnt + 1, m), notIncluded);
	else return notIncluded;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>>house;
	vector<pair<int, int>>chicken;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int info;
			cin >> info;
			if (info == 1)house.push_back({ i,j });
			else if (info == 2)chicken.push_back({ i,j });
		}
	}

	vector<vector<int>>dist(house.size(), vector<int>(chicken.size()));
	for (int i = 0; i < house.size(); i++) {
		for (int j = 0; j < chicken.size(); j++) {
			dist[i][j] = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);

		}
	}

	int result = 10000;
	for (int i = 0; i < chicken.size(); i++) {
		vector<int>minLi(house.size());
		for (int j = 0; j < house.size(); j++) {
			minLi[j] = dist[j][i];
		}
		result=min(result,select(i+1, dist, minLi, 1, m));
	}

	cout << result;
}