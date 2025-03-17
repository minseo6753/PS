#include <iostream>
using namespace std;


int f(int* po, int start, int end) {

    if (start < end) {
        int i = start;
        int j = start + 1;

        while (j <= end) {
            if (po[start] > po[j]) {

                int x = po[i + 1];
                po[i + 1] = po[j];
                po[j] = x;

                i += 1;
                j += 1;

            }
            else {
                j += 1;
            }
        }
        int y = po[start];
        po[start] = po[i];
        po[i] = y;

        f(po, start, i - 1);
        f(po, i + 1, end);
    }
    return 0;
}
int main() {
    int n;
    cin >> n;
    int* po = new int[n];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        po[i] = a;
    }

    f(po, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << po[i] << endl;
    }
    delete[]po;
    return 0;
}