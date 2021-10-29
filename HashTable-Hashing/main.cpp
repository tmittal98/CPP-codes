#include <iostream>
#include "hashtable.h"

using namespace std;

int main() {

	HashTable<int> price_menu(20);

	price_menu.insert("Burger", 80);
	price_menu.insert("Coke", 40);
	price_menu.insert("Sandwich", 50);
	price_menu.insert("Roll", 60);
	price_menu.insert("Pizza", 120);
	price_menu.insert("BurgerPizza", 150);
	price_menu.insert("Meal365", 200);
	price_menu.insert("ChocoFudge", 100);
	price_menu.insert("Dosa", 120);
	price_menu.insert("Noodles", 60);
	price_menu.insert("Juice", 100);

	price_menu.print();

	int* p = price_menu.search("Dosa");

	if (p) {
		cout << "The price of Dosa is " << *p << endl;
	}
	else {
		cout << "Dosa Not available" << endl;
	}

	price_menu.erase("Dosa");

	p = price_menu.search("Dosa");

	if (p) {
		cout << "The price of Dosa is " << *p << endl;
	}
	else {
		cout << "Dosa Not available" << endl;
	}

	price_menu["Dosa"] = 60;

	price_menu["Dosa"] += 10;

	cout << "Price of Dosa " << price_menu["Dosa"] << endl;
	return 0;
}