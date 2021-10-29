//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;

	Node(int val) {
		data = val;
		left = right = NULL;
	}
};

// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

vector <int> zigZagTraversal(Node* root);

int main()
{
	int t;
	scanf("%d ", &t);
	while (t--)
	{
		string s;
		getline(cin, s);
		Node* root = buildTree(s);
		vector <int> res = zigZagTraversal(root);
		for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
// Contributed by: Hashit Sidhwa

// } Driver Code Ends


//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

vector<int> convertQ2V(queue<Node*> q, int i) {

	vector<int>v;

	while (q.front() != NULL) {
		v.push_back(q.front()->data);
		q.pop();
	}


	if (i & 1) {
		reverse(v.begin(), v.end());
	}

	return v;

}
// return a vector containing the zig zag level order traversal of the given tree
vector <int> zigZagTraversal(Node* root)
{
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	vector<int> v;
	v.push_back(root->data);

	int i = 0;

	while (!q.empty()) {

		Node* f = q.front();
		q.pop();

		if (f == NULL) {
			i++;
			if (q.empty()) {
				break;
			}
			else {
				q.push(NULL);
				vector<int> vec = convertQ2V(q, i);

				for (auto x : vec) {
					v.push_back(x);
				}

				continue;
			}
		}

		if (f->left) {
			q.push(f->left);
		}
		if (f->right) {
			q.push(f->right);
		}
	}

	return v;
}