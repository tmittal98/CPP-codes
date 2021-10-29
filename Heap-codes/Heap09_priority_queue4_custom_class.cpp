#include <iostream>
#include <queue>

using namespace std;

class Person {

public:
	string name;
	int age;

	Person() {

	}

	Person(string n, int a) {
		this->name = n;
		this->age = a;
	}
};

class PersonCompare {

public:
	bool operator()(Person a, Person b) {
		return a.age < b.age;
	}
};


int main() {

	int n; cin >> n;

	priority_queue<Person, vector<Person>, PersonCompare> pq;

	for (int i = 0; i < n; i++) {

		string name;
		int age;

		cin >> name >> age;

		Person p(name, age);

		pq.push(p);

	}

	int k = 3;

	cout << endl << "-------------------------------------" << endl;
	for (int i = 0; i < n; i++) {

		Person p = pq.top();

		cout << p.name << " " << p.age << endl;
		pq.pop();

	}

	cout << endl << "-------------------------------------" << endl;

	return 0;
}