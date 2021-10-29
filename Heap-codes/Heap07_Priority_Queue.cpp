#include <iostream>
#include <queue>

using namespace std;

int main() {

	priority_queue<int> pq;//Max Heap by default

	priority_queue<int, vector<int>, greater<int>> p;

	int n; cin >> n;

	//Inserting elements into Heap in O(logN)
	for (int i = 0; i < n; i++) {
		int no; cin >> no;
		pq.push(no);
		p.push(no);
	}

	//Remove all elements from the Heap in O(logN)
	while (!pq.empty()) {

		cout << pq.top() << " ";
		pq.pop();

	}

	cout << endl;

	while (!p.empty()) {

		cout << p.top() << " ";
		p.pop();

	}
	return 0;
}