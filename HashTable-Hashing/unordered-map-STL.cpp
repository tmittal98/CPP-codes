#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {

	unordered_map<string, vector<string> > phonebook;

	phonebook["Mini"].push_back("9339116843");
	phonebook["Papa"].push_back("9831844984");
	phonebook["Papa"].push_back("9831XXXXXX");
	phonebook["Mini"].push_back("933XXXXXXX");
	phonebook["Baba"].push_back("9831111199");
	phonebook["Baba"].push_back("9831XXXXXX");

	for (unordered_map<string, vector<string>>:: iterator it = phonebook.begin() ; it != phonebook.end() ; it++) {

		cout << "Name : " << it->first << "->";

		for (auto v : it->second) {
			cout << v << "->";
		}
		cout << endl;
	}

	string name ; cin >> name;

	if (phonebook.count(name) == 0) {
		//not present in the phonebook
		cout << "this name is not present" << endl;
	}

	else {
		for (auto no : phonebook[name]) {
			cout << no << "->";
		}
	}
}