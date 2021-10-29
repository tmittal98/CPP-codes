#include <iostream>
#include <vector>
#include <map>

using namespace std;

//make tree class
class Node {
public:
	int data;
	Node* left;
	Node* right;


	Node(int d) {
		data = d;
		left = right = nullptr;
	}
};

void verticalOrderPrint(Node* root, int d, map<int, vector<int>> &m) {

	if (root ==  NULL) {
		return;
	}

	m[d].push_back(root->data);

	verticalOrderPrint(root->left, d - 1, m);
	verticalOrderPrint(root->right, d + 1, m);

	return;
}
int main() {

	Node * root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	map<int, vector<int>> m;

	int d = 0;

	verticalOrderPrint(root, d, m);

	for (auto p : m) {
		// cout << p.first << "->";
		for (auto q : p.second) {
			cout << q << ",";
		}
		cout << endl;
	}
	return 0;
}