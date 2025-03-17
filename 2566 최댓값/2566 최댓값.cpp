#include <iostream>
using namespace std;
int main() {
    int m=0,n = 0;

    int arr[81];
    for (int a = 0; a < 9; a++) {
        for (int b = 0; b < 9; b++) {
            int p;
            cin >> p;
            arr[a * 9 + b] = p;
            if (p > m) {
                m = p;
                n = a * 9 + b;
            }
        }
    }
    cout << m << endl;
    cout << n / 9+1 << " " << n % 9+1;
}