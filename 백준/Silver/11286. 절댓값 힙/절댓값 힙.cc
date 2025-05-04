#include<iostream>
using namespace std;

class Heap {
	
	int size;
	int* arr;

public:
	Heap(int c) { size = 0; arr = new int[c + 1]; }
	void Push(int);
	void Pop();
	
};

void Heap::Push(int x) {

	arr[++size] = x;
	int p = size;
	int q = p / 2;
	while (q > 0 && (abs(arr[p]) < abs(arr[q])||(arr[p]<0&&-arr[p]==arr[q]))) {
		int temp = arr[q];
		arr[q] = arr[p];
		arr[p] = temp;
		p = q;
		q /= 2;
	}
}

void Heap::Pop() {
	
	if (size == 0)cout << 0 << '\n';
	else {

		cout << arr[1] << '\n';
		arr[1] = arr[size--];

		int p = 1;
		int q = 2;

		while (q<=size) {
			if (q + 1 <= size && (abs(arr[q + 1]) < abs(arr[q]) || (arr[q + 1] < 0 && -arr[q + 1] == arr[q]))) {
				q++;
			}
			if (abs(arr[q]) < abs(arr[p]) || (arr[q] < 0 && -arr[q] == arr[p])) {
				int temp = arr[q];
				arr[q] = arr[p];
				arr[p] = temp;

				p = q;
				q *= 2;
			}
			else break;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	Heap h(n);
	while (n--) {
		int x;
		cin >> x;
		if (x == 0)h.Pop();
		else h.Push(x);
	}
}