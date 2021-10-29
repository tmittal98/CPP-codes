#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {

	list<int> l;
	//initialization
	list<int> l1{1, 2, 3, 4, 5, 6};

	list<string> l2{"apple", "orange", "banana", "mango"};

	l1.push_front(0);
	l1.push_back(7);

	for (auto x : l1) {
		cout << x << "->";
	}
	cout << endl;


	cout << "THE FORNT ELEMENT IS = " << l1.front() << endl;
	cout << "THE BACK ELEMENT IS = " << l1.back() << endl;

	l1.pop_front();
	l1.pop_back();

	for (auto x : l1) {
		cout << x << "->";
	}
	cout << endl;

	cout << "THE FORNT ELEMENT IS = " << l1.front() << endl;
	cout << "THE BACK ELEMENT IS = " << l1.back() << endl;


	l2.push_back("papaya");

	for (auto s : l2) {
		cout << s << "->";
	}
	cout << endl;

	l1.reverse();

	for (auto it = l1.begin(); it != l1.end(); it++) {
		cout << *it << "->";
	}
	cout << endl;

	l1.sort();

	for (auto it = l1.begin(); it != l1.end(); it++) {
		cout << *it << "->";
	}
	cout << endl;

	//remove function removes all the instances
	l1.remove(1);

	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(1);
	l1.push_back(3);
	l1.push_back(1);

	for (auto it = l1.begin(); it != l1.end(); it++) {
		cout << *it << "->";
	}
	cout << endl;

	l1.remove(1);

	for (auto it = l1.begin(); it != l1.end(); it++) {
		cout << *it << "->";
	}
	cout << endl;

	auto inst = l1.begin();

	l1.erase(inst);

	for (auto it = l1.begin(); it != l1.end(); it++) {
		cout << *it << "->";
	}
	cout << endl;

	l1.remove(2);

	for (auto it = l1.begin(); it != l1.end(); it++) {
		cout << *it << "->";
	}
	cout << endl;

	l1.remove(3);

	for (auto it = l1.begin(); it != l1.end(); it++) {
		cout << *it << "->";
	}
	cout << endl;


	//IMPLEMENT GRAPH USING ADJACENCY LIST WITH THE HELP OF LIST STL

	//input no of edges
	int n; cin >> n;

	list<pair<int, int>> * li;

	li = new list<pair<int, int>>[n];

	//input graph

	for (int i = 0; i < n; i++) {

		int x, y, wt;
		cin >> x >> y >> wt;

		li[x].push_back(make_pair(y, wt));
		li[y].push_back(make_pair(x, wt));
	}

	for (int i = 0; i < n; i++) {
		//print the linked list
		cout << "LINKED LIST " << i << " -> ";
		for (auto xp : li[i]) {
			cout << "(" << xp.first << "," << xp.second << ") , ";
		}
		cout << endl;
	}

	return 0;
}