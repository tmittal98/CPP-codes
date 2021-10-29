#include <iostream>
#include<list>
using namespace std;

template<typename T>
class Queue {
private:
	int cs;
	list<T> qu;
public:
	Queue() {
		this->cs = 0;
	}
	//empty
	bool empty() {
		return this->cs == 0;
	}
	//enqueue
	void enqueue(T data) {

		this->qu.push_back(data);
		this->cs += 1;
	}
	//dequeue
	void dequeue() {
		if (!empty()) {
			this->qu.pop_front();
			this->cs -= 1 ;
		}
		else {
			cout << "!!Queue is empty!!";
		}
	}
	//front
	T front() {
		return this->qu.front();
	}
};

int main() {

	Queue<int> q;

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);

	while (!q.empty()) {
		cout << q.front() << " ";
		q.dequeue();
	}

	cout << endl;

	Queue<char> qu;

	qu.enqueue('a');
	qu.enqueue('b');
	qu.enqueue('c');
	qu.enqueue('d');

	while (!qu.empty()) {
		cout << qu.front() << " ";
		qu.dequeue();
	}
	cout << endl;
	return 0;
}