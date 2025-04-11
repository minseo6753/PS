#include<iostream>
#include<vector>
using namespace std;

class Heap {
	int v[100001];
	int len;
public:
	Heap() { len = 0; }
	void Insert(int);
	void Pop();
};

void Heap::Insert(int x) {

	len++;
	v[len] = x;

	int i = len;
	while (i / 2 && v[i] > v[i / 2]) {
		int temp = v[i];
		v[i] = v[i / 2];
		v[i / 2] = temp;
		i /= 2;
	}

}

void Heap::Pop() {
	if (len < 1) {
		cout << 0 << '\n';
		return;
	}
	cout << v[1] << '\n';
	v[1] = v[len];
	len--;

	int i = 1;
	int j = 2;
	while (j <= len) {

		if (j + 1 <= len && v[j + 1] > v[j])j++;
		if (v[j] > v[i]) {
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
			i = j;
			j = 2 * i;
		}
		else break;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	Heap h;
	while (n--) {
		int x;
		cin >> x;
		if (x) {
			h.Insert(x);
		}
		else h.Pop();
	}
}