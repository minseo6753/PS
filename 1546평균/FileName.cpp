#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	double score[1000];
	double max = 0;
	for (int i = 0; i < n; i++) {
		cin >> score[i];
		if (score[i] > max) {
			max = score[i];
		}
	}

	double sum = 0;
	for (int i = 0; i < n; i++) {
		score[i] = score[i] / max * 100;
		sum += score[i];
	}
	cout << sum / n;

}