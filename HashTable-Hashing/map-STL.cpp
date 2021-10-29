#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

	map<string, int> fruits;

	//1. Insertion
	fruits.insert(make_pair("Banana", 20));
	fruits.insert(make_pair("Pineapple", 100));
	fruits.insert(make_pair("Apple", 150));
	fruits.insert(make_pair("Papaya", 60));

	fruits["Grapes"] = 80;

	pair<string, int> p;

	p.first = "Strawberry";
	p.second = 300;

	fruits.insert(p);

	for (auto it = fruits.begin() ; it != fruits.end() ; it++) {
		cout << it->first << " " << it->second << endl;
	}

	//2. Search

	string fruit; cin >> fruit;

	map<string, int>::iterator it = fruits.find(fruit);

	if (it != fruits.end()) {
		cout << "price of " << fruit << " " << it->second << endl;
	}

	else {
		cout << fruit << " not found" << endl;
	}

	if (fruits.count("Banana")) {
		cout << "Price of Banana is " << fruits["Banana"] << endl;
	}

	else {
		cout << "Banana not found :< " << endl;
	}

	//3. Erase

	fruits.erase("Banana");

	//4 Update

	fruits["Banana"] = 40;

	fruits["Banana"] += 10;

	// for (map<string, int>::iterator it = fruits.begin() ; it != fruits.end() ; it++) {

	// 	cout << it->first << " and " << it->second << endl;
	// }

	for (auto fruit : fruits) {
		cout << fruit.first << " and " << fruit.second << endl;
	}
	return 0;
}

