#include<iostream>

#include<cmath>
using namespace std;

int r, c;

void z(int len, int hmid,int wmid, int num) {

	if (len == 1) {
		cout << num;
		return;
	}

	len /= 2;

	if (r < hmid && c < wmid)z(len, hmid - len / 2, wmid - len / 2, num);
	else if (r < hmid && c >= wmid)z(len, hmid - len / 2, wmid + len / 2, num + len * len);
	else if (r >= hmid && c < wmid)z(len, hmid + len / 2, wmid - len / 2, num + 2 * len * len);
	else z(len, hmid + len / 2, wmid + len / 2, num + 3 * len * len);
}

int main() {
	int n;
	cin >> n >> r >> c;

	int len = pow(2, n);
	z(len, len / 2, len/2, 0);

}