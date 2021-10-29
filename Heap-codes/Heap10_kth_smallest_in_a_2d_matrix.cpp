#include <iostream>
#include <queue>

using namespace std;

int main() {

	priority_queue<int> pq;

	pq.push(6);
	pq.push(6);
	pq.push(6);
	pq.push(6);


	while (!pq.empty()) {

		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}