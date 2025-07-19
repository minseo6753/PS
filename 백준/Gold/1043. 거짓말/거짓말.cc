#include<iostream>
#include<vector>
using namespace std;

struct Set;

struct Person {
	
	Person* next;
	Set* set;

	Person() { next = nullptr; set = nullptr; }
	
};

struct Set {
	Person* head;
	Person* tail;
	int party;

	Set() { head = tail = nullptr; party = 0; }
};

void join(Set* s1, Set* s2) {
	Person* tmp = s2->head;
	while (tmp != nullptr) {
		tmp->set = s1;
		tmp = tmp->next;
	}
	s1->tail->next = s2->head;
	s1->tail = s2->tail;

	s1->party += s2->party;

	s2->head = s2->tail = nullptr;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int cnt;
	cin >> cnt;

	bool know[51] = { 0 };
	for (int i = 1; i <= cnt; i++) {
		int ans;
		cin >> ans;
		know[ans] = true;
	}

	Person* people = new Person[n + 1];
	Set* sets = new Set[n + 1];
	for (int i = 1; i <= n; i++) {
		
		people[i].set = &sets[i];
		sets[i].head = sets[i].tail = &people[i];
	}

	for (int i = 1; i <= m; i++) {
		cin >> cnt;
		int target;
		cin >> target;
		people[target].set->party++;
		for (int j = 1; j < cnt; j++) {
			int ans;
			cin >> ans;
			if (people[target].set != people[ans].set) {
				join(people[target].set, people[ans].set);
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (know[i]) {
			sum += people[i].set->party;
			people[i].set->party = 0;
		}
	}
	cout << m - sum;
}