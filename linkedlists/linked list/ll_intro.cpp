#include<iostream>
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

void insertAtHead(node* &head, int data) {

	node* newNode = new node(data);

	newNode->next = head;
	head = newNode;

	return;
}

int length(node* head) {

	int len = 0;

	while (head != NULL) {
		len += 1;
		head = head->next;
	}

	return len;
}


void insertAtEnd(node* &head, int data) {

	if (head == NULL) {
		insertAtHead(head, data);
		return;
	}

	node* newNode = new node(data);

	node* temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;
	return;
}

void insertAtMiddle(node* &head, int data, int pos) {

	node* newNode = new node(data);
	//if head is null then insert at begining
	if (head == NULL) {
		newNode = head;
		head = newNode;
		return;
	}

	//if the given position is larger or equal to length of linked list
	if (pos >= length(head)) {
		insertAtEnd(head, data);
		return;
	}

	//for inserting data at position pos we need pos-1 jumps

	int jump = 1;
	node* temp = head;
	while (jump <= pos - 1) {
		jump++;
		temp = temp->next;
	}

	newNode -> next = temp->next->next;
	temp->next = newNode;
	return;
}

void printLL(node* head) {

	while (head != NULL) {
		cout << head->data << "->";
		head = head->next;
	}
	cout << endl;
	return;
}

//search algortihms for linked list
bool searchRecursive(node* head, int key) {


	//base case
	if (head == NULL) {
		return false;
	}

	if (head->data == key) {
		return true;
	}

	return searchRecursive(head->next, key);

}

bool searchIterative(node* head, int key) {

	while (head != NULL) {

		if (head->data == key) {
			return true;
		}
		head = head->next;
	}

	return false;
}

//build a linkied list by taking inputs
void build(node* &head) {

	int data;
	cin >> data;

	while (data != -1) {

		insertAtEnd(head, data);
		cin >> data;
	}

	return;

}

//operator overloading for linked list

istream &operator >> (istream &is, node* &head) {

	build(head);
	return is;
}

ostream &operator << (ostream &os, node* head) {

	printLL(head);
	return os;
}

void deleteHeadNode(node* &head) {

	if (head == NULL) {
		return;
	}
	node* temp = head;
	head = head->next;
	delete temp;
	return;

}

void deleteTailNode(node* &head) {

	if (head == NULL) {
		return;
	}

	node* prev = head;
	node* temp = head;

	while (temp ->next != NULL) {

		prev = temp;
		temp = temp->next;
	}

	prev->next = NULL;
	delete temp;
	return;
}

void deleteMiddleNode(node* &head, int pos) {

	if (head == NULL) {
		return;
	}

	if (pos == 0) {
		deleteHeadNode(head);
		return;
	}
	if (pos >= length(head)) {
		deleteTailNode(head);
		return;
	}

	node* prev = head;
	node* temp = head;
	int jump = 1;

	while ( jump <= pos - 1) {
		prev = temp;
		temp = temp->next;
		jump += 1;
	}

	prev -> next = temp->next;
	delete temp;

	return;
}
//find the middle of the linked list using runner technique or two pointer technique
node* midpointOfLL(node* head) {

	node* fast = head;
	node* slow = head;

	if (head == NULL or head->next == NULL) {
		//one node or 0 node
		return head;
	}

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

//kth node from the last of a linked list using runner technique
node* kthnodefromLast(node* head, int k) {

	if (head == NULL or head->next == NULL) {
		return head;
	}
	node* fast = head;
	node* slow = head;

	//first travel k jumps from fast pointer
	for (int i = 1; i < k ; i++) {
		fast = fast->next;
	}

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}

//merge two sorted linked list using recursion

node* merge(node* a, node * b) {

	//base case
	if (a == NULL) {
		return b;
	}
	else if (b == NULL) {
		return a;
	}

	node* c = NULL;
	if ( a->data < b->data) {
		c = a;
		c->next = merge(a->next, b);
	}
	else {
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}
//merge sort on linked list

node* mergesort(node* head) {

	// cout << "CP1" << endl;
	//base case
	if (head == NULL or head->next == NULL) {
		return head;
	}
	// cout << "CP2" << endl;

	//divide the linked list from middle
	node* midpoint = midpointOfLL(head);
	node* a = head;
	node* b = midpoint->next;
	midpoint->next = NULL;

	// cout << "CP3" << endl;

	//recursively sort the two parts
	a = mergesort(a);
	b = mergesort(b);

	// cout << "CP4" << endl;

	//merge the two sorted arrays
	node* c = merge(a, b);

	return c;
}

//Floyd's cycle Algorithm
bool detectAndRemoveCycle(node* head) {

	node* fast = head;
	node* slow = head;
	bool isCycle = false;

	while (fast != NULL or fast->next != NULL) {

		fast = fast->next->next;
		slow = slow->next;

		//at anymoment if slow equals fast then the cycle is present
		if (fast == slow) {
			isCycle = true;
			break;
		}
	}

	if (isCycle) {

		//we have to remove the cycle

		slow = head;

		while (fast != slow) {
			fast = fast->next;
			slow = slow->next;
		}

		while (fast->next != slow) {
			fast = fast->next;
		}

		fast->next = NULL;
	}

	return isCycle;
}

int main() {

	node* head = NULL;

	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	insertAtEnd(head, 4);
	insertAtEnd(head, 5);
	insertAtMiddle(head, 6, 5);
	printLL(head);

	if (searchRecursive(head, 9)) {
		cout << "9 found in linked list" << endl;
	}
	else {
		cout << "the element is not present" << endl;
	}

	if (searchIterative(head, 10)) {
		cout << "element 10 is present in linked list" << endl;
	}
	else {
		cout << "element is not present" << endl;
	}

	// node* newHead = NULL;

	// build(newHead);
	// printLL(newHead);

	// node* head1 = NULL;
	// node* head2 = NULL;

	// cin >> head1 >> head2;
	// cout << head1 << head2;

	deleteHeadNode(head);
	deleteTailNode(head);
	deleteMiddleNode(head, 3);
	cout << head;

	//midpoint of linked list
	node* res = midpointOfLL(head);

	if (res != NULL) {
		cout << "midpoint of linked list is " << res->data << endl;
	}

	//find kth node from the end
	int k = 2;
	res = kthnodefromLast(head, k);

	if (res) {
		cout << "Kth node from end = " << res->data << endl;
	}

	//merge two sortd linked list
	// node* a = NULL;
	// node* b = NULL;

	// cin >> a >> b;
	// cout << a << b;

	// node* ab = merge(a, b);
	// cout << "THE MEGRED SORTED LINKED LISTS ARE :: " << endl;
	// cout << ab;

	//merge sort on linked list
	// node* newHead1 = NULL;
	// cin >> newHead1;
	// cout << newHead1;
	// cout << "THE SORTED LINKED LIST IS :: " << endl;
	// newHead1 = mergesort(newHead1);
	// cout << newHead1;


	//Floyd's Cycle Algorithm
	node* newHead1 = NULL;
	cin >> newHead1;

	node* temp = newHead1;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newHead1;

	if (detectAndRemoveCycle(newHead1)) {
		cout << "CYCLE IS PRESENT" << endl;
	}
	cout << newHead1;


	cout << "THE END" << endl;
	return 0;
}