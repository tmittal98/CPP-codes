#include <iostream>
#include <unordered_map>

using namespace std;

class listnode {
public:
	int data;
	listnode* next;

	listnode(int d) {
		this->data = d;
		this->next = NULL;
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
	cout << endl;
	return;
}

listnode* deleteKSumNodes(listnode* &head, int k) {

	//Implement prefixSum algo
	unordered_map<int, listnode*> mp;

	//create a dummy node for prefixsum = 0
	int pSum = 0;
	listnode* n = new listnode(0);
	mp.insert(0, n);

	//traverse the linked list
	while (head) {

		//calculate pSum
		pSum += head->data;

		//pSum found in map
		if (mp.find(pSum - k) != mp.end()) {
			//delete the nodes
			listnode* to_delete = mp[pSum - k]->next;

			int sum = pSum;
			while (to_delete != head) {
				sum += to_delete->data;
				mp.erase(sum);
				listnode *save = to_delete;
				to_delete = to_delete->next;
				delete save;
			}
			listnode* save = head;
			//change the link
			mp[pSum]->next = head->next;
		}
		//pSum not found in map
		else {
			//insert the pSum into the map with corresponding node
			mp.insert(pSum, head);
		}
		head = head->next;
	}

	listnode* it = mp.begin();
	it = it->next;
	return it;
}
int main() {

	listnode* head = NULL;
	buildlist(head);
	printlist(head);

	int k;
	cout << "Enter the value of k";
	cin >> k;

	head = deleteKSumNodes(head, k);

	printlist(head);
	return 0;
}
