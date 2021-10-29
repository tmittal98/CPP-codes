#include<iostream>
#include<set>
#include<vector>

using namespace std;

class car {
public:
	int regno;
	string color;
public:
	car(int no, string clr) {
		regno = no;
		color = clr;
	}

};
int main() {
	vector<int> v;
	int a[10];
	set<int> s;

	v.push_back(5);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);

	s.insert(5);
	s.insert(5);
	s.insert(5);
	s.insert(4);
	s.insert(2);
	s.insert(3);
	s.insert(9);

	for (int e : v) {
		cout << e << " ";
	}
	cout << endl;
	for (int e : s) {
		cout << e << " ";
	}
	cout << endl;
	// it
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	// set<car> carset;

	// car * c1 = new car(123, "red");
	// car * c2 = new car(143, "black");
	// car * c3 = new car(153, "green");

	// // cout << c1->regno;
	// carset.insert(c1);
	// carset.insert(c2);
	// carset.insert(c3);

	// for (auto c : carset) {
	// 	cout << c->regno << " " << c->color << endl;
	// }
	if (s.empty()) {
		cout << "empty :( set";
	}
	else {
		cout << "ok ";
	}
	cout << s.max_size();
	cout << "\n" << s.size();

	// erase,find,count,clear

	s.erase(5);

	cout << endl;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	/* Stl */
	vector
	pair
	map
	set
	unordered_map
	unordered_set
	sort(s.begin(), s.end(), mycomp);




	cout << endl;
	return 0;
}