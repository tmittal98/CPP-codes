#include <iostream>
#include <unordered_map>

using namespace std;

class node {
public:
	int data;
	node* next;

	node(int d) {
		this->data = d;
		this->next = NULL;
	}
};


void buildlist(node* &head) {

	int d; cin >> d;

	node* temp = NULL;

	if (head != NULL)
		temp = head;

	while (d != -1) {

		if (head == NULL) {
			node* n = new node(d);
			head = n;
			temp = head;
		}
		else {
			node *n = new node(d);
			temp ->next = n;
			temp = temp->next;
		}
		cin >> d;
	}
	return;
}

void printlist(node* head) {

	while (head != NULL) {
		cout << head->data << "->";
		head = head->next;
	}
	cout << endl;
	return;
}

int length(node* head) {

	int len = 0;

	while (head) {
		head = head->next;
		len++;
	}
	return len;
}
node* reverseGroupSizeK(node* head, int k) {

	//base case
	if (length(head) <= k) {
		//reverse the small linked list
		node* c = head;
		node* n = NULL;
		node* p = NULL;

		while (c != NULL) {
			n = c->next;
			c->next = p;
			p = c;
			c = n;
		}
		return p;
	}

	node* temp = head;
	node* prev = temp;
	int count = 0;

	//take k jumps and call recursion
	while (temp != NULL and count < k ) {
		prev = temp;
		temp = temp->next;
		count++;
	}
	prev->next = NULL;
	node* to_reverse = reverseGroupSizeK(temp, k);

	node* c = head;
	node* p = NULL;
	node* n;

	node* save = c;

	count = 0;
	while (c != NULL and count < k ) {
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}

	head->next = to_reverse;
	return p;

}
int main() {

	node* head = NULL;

	buildlist(head);


	int k;
	cout << "Enter the value of k";
	cin >> k;

	printlist(reverseGroupSizeK(head, k));

	return 0;
}