#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int h=0, g=0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'H' ||s[i]== 'A' ||s[i]== 'P' ||s[i]== 'Y')h++;
		if (s[i] == 'S' ||s[i]== 'A' ||s[i]== 'D')g++;
	}
	
	
	if (h ==0&& g == 0)cout << "50.00";
	else {
		cout << fixed;
		cout.precision(2);

		cout << round((float(h) / (h + g))*10000)/100;
	}


}