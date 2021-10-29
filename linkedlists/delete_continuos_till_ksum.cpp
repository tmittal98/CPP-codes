#include <iostream>

using namespace std;

class listnode {
	int data;
	listnode* next;

public:
	listnode(int d) {
		data = d;
		next = NULL;
	}
};

void buildlist(listnode* &head) {

	int d; cin >> d;

	listnode* temp = NULL;

	if (head != NULL)
		temp = head;

	while (d != -1) {

		if (head == NULL) {
			listnode* n = new listnode(d);
			head = n;
			temp = head;
		}
		else {
			listnode *n = new listnode(d);
			temp ->next = n;
			temp = temp->next;
		}
		cin >> d;
	}
	return;
}

void printlist(listnode* head) {

	while (head != NULL) {
		cout << head->data << "->";
		head = head->next;
	}
	return;
}
int main() {

	listnode* head = NULL;
	buildlist(head);
	printlist(head);

	return 0;
}
