#include<iostream>

using namespace std;

struct LL {
	string s;
	LL* prepo=nullptr;
	LL* postpo=nullptr;

};

int main() {
	int n;
	cin >> n;
	
	string is;
	cin >> is;
	LL il;
	il.s = is;

	LL* head = &il;
	LL* po = &il;

	for (int i = 0; i < n - 1; i++) {
		string s;
		cin >> s;

		if (po->s.length() < s.length() || (po->s.length() == s.length() && po->s < s)) { //오른쪽으로 이동

			while (po->s.length() < s.length()) {
				if (po->postpo == nullptr)break;
				po = po->postpo;
			}
			if (po->s.length() < s.length()) {
				LL* a = new LL();
				a->s = s;
				a->prepo = po;
				po->postpo = a;
				continue;
			}

			while (po->s.length() == s.length() && po->s < s) {
				if (po->postpo == nullptr)break;
				po = po->postpo;
			}
			if (po->s.length() == s.length() && po->s < s) {
				LL* a = new LL();
				a->s = s;
				a->prepo = po;
				po->postpo = a;
				continue;
			}

			if (po->s != s) {
				LL* a=new LL();
				a->s = s;
				a->prepo = po->prepo;
				a->postpo = po;
				po->prepo->postpo = a;
				po->prepo = a;
			}

			
		}
		else if (po->s.length() > s.length() || (po->s.length() == s.length() && po->s > s)) { //왼쪽으로 이동
			
			while (po->s.length() > s.length()) {
				if (po->prepo == nullptr)break;
				po = po->prepo;
			}
			if (po->s.length() > s.length()) {
				LL* a=new LL();
				a->s = s;
				a->postpo = po;
				po->prepo = a;
				head = a;
				continue;
			}

			while (po->s.length() == s.length() && po->s > s) {
				if (po->prepo == nullptr)break;
				po = po->prepo;
			}
			if (po->s.length() == s.length() && po->s > s) {
				LL* a=new LL();
				a->s = s;
				a->postpo = po;
				po->prepo = a;
				head = a;
				continue;
			}

			if (po->s != s) {
				LL* a=new LL();
				a->s = s;
				a->postpo = po->postpo;
				a->prepo = po;
				po->postpo->prepo = a;
				po->postpo = a;
			}

		}
		
	}

	while (head != nullptr) {
		cout << head->s << endl;
		head = head->postpo;
	}

}