#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 1;
        return 0;
    }
    int fac = 1;
    do {
        fac *= n;
    } while (--n);
    cout << fac;
}