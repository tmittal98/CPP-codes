#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Item {
    string name;
    int quantity;
    int price;
};

class ShoppingCart {
private:
    vector<Item> item;
    int total_price;
public:
    ShoppingCart();
    void addItem(string name, int quantity, int price);
    void removeItem(string name, int quantity);
    int getTotal();
};

ShoppingCart::ShoppingCart() {
    cout << "Creating a new shopping cart" << endl;
    total_price = 0;
}

void ShoppingCart::addItem(string name, int quantity, int price) {
    for (int i = 0; i < item.size(); i++) {
        if (item[i].name == name) {
            item[i].quantity += quantity;
            return;
        }
    }

    Item temp;
    temp.name = name;
    temp.quantity = quantity;
    temp.price = price;
    item.push_back(temp);
}

void ShoppingCart::removeItem(string name, int quantity) {
    for (int i = 0; i < item.size(); i++) {
        if (item[i].name == name) {
            if (item[i].quantity >= quantity) {
                item[i].quantity -= quantity;
                return;
            }
            cout << "Not enough items present in the cart to be removed" << endl;
            return;
        }
    }
    cout << "This item is not present in the cart" << endl;
}

int ShoppingCart::getTotal() {
    total_price = 0;
    for (int i = 0; i < item.size(); i++) {
        total_price += item[i].quantity * item[i].price;
    }
    return total_price;
}

int main() {
    ShoppingCart cart;
    cart.addItem("Maggi", 10, 5);
    cart.addItem("Biryani", 2, 15);
    cart.addItem("Ketchup", 1, 5);
    cout << "Total cost: " << cart.getTotal() << endl;
    cart.addItem("Football", 2, 15);
    cart.removeItem("Maggi", 4);
    cart.removeItem("Ketchup", 2);
    cout << "Total cost: " << cart.getTotal() << endl;
    cart.addItem("Candy", 15, 2);
    cart.removeItem("Bat", 1);
    cout << "Total cost: " << cart.getTotal() << endl;
}