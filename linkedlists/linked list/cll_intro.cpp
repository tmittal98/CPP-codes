#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;

	node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

//function declarations
void push(node*&head, int data);
void printList(node* head);
node* getNode(node* &head, int data);
void deleteNode(node* &head, int data);


void push(node* &head, int data) {

	//make a new node with the given data and mark it's next to head
	node* newNode = new node(data);
	newNode->next = head;

	//traverse till the tail of the node and update the tail->next = newNode
	if (head != NULL) {
		node* temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}

		temp->next = newNode;
	}
	else if (head == NULL) {
		newNode ->next = newNode;
	}

	//update head to newNode
	head = newNode;

	return;
}

void printList(node* head) {

	node* temp = head;

	//if no node is present in cll
	if (head == NULL) {
		return;
	}
	//if single node is present in cll
	if (head ->next == head) {
		cout << head->data;
		return;
	}
	while (temp->next != head) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << temp->data << "->" << head->data << endl;
}

node* getNode(node*& head, int d) {

	if (head == NULL) {
		return NULL;
	}

	node* temp = head;

	while (temp->next != head) {
		if (temp->data == d) {
			return temp;
		}
		temp = temp->next;
	}

	//check for tail node
	if (temp -> data == d) {
		return temp;
	}
	else
		return NULL;
}

void deleteNode(node* &head, int d) {

	node* del = getNode(head, d);

	if (del == NULL) {
		return;
	}

	if (del == head) {
		head = head->next;
	}

	node* temp = head;

	while (temp->next != del) {
		temp = temp->next;
	}

	temp -> next = del -> next;

	delete del;

	return;
}

int main() {

	node* head = NULL;

	push(head, 1);
	push(head, 2);
	push(head, 3);
	push(head, 4);
	push(head, 5);
	push(head, 6);
	push(head, 7);

	cout << head->data << endl;

	printList(head);

	node* temp = getNode(head, 4);
	cout << temp->data << endl;
	deleteNode(head, 4);
	temp = getNode(head, 4);
	if (temp == NULL) {
		cout << "not present" << endl;
	}
	return 0;
}