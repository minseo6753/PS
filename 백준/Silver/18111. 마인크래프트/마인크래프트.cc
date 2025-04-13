#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m, b;
	cin >> n >> m >> b;

	vector<int>v(n * m);
	int sum = 0;
	for (int i = 0; i < n * m; i++) {
		cin >> v[i];
		sum += v[i];
	}
	int height = sum / (n * m);
	int htemp = height;
	int time = 2 * n * m * 256;
	while (true) {
		int timetemp = 0;
		int btemp = b;
		for (int i = 0; i < n * m; i++) {
			if (v[i] < htemp) {
				btemp -= htemp - v[i];
				timetemp += htemp-v[i];
			}
			else if (v[i] > htemp) {

				btemp += v[i] - htemp;
				timetemp += 2*(v[i]-htemp);
			}
			
		}
		if (btemp < 0)break;
		if (timetemp > 2 * n * m * 256)break;
		if (timetemp <= time) {
			time = timetemp;
			height = htemp;
		}

		htemp++;
	}
	cout << time << ' ' << height;
}