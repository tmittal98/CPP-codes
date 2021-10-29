#include <iostream>
using namespace std;

istream& operator<<(istream &is,node* &head){
    buildList(head);
    return is;
}

ostream& operator<<(ostream &os,node* &head){
    print(head);
    return os;
}
int main() {
	cout<<"GfG!";
	return 0;
}