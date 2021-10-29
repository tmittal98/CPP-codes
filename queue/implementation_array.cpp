#include <iostream>

using namespace std;

template<typename T>
class Queue {

private:
	T *arr;
	int cs;
	int ms;
	int front;
	int rear;
public:
	Queue(int default_size = 7) {

		this->ms = default_size;
		this->cs = 0;
		this->arr = new T[this->ms]();
		this->front = 0;
		this->rear = default_size - 1;
	}
	//empty
	bool empty() {
		return this->cs == 0;
	}
	//full
	bool full() {
		return this->cs == this->ms;
	}
	//front
	T getFront() {
		return this->arr[this->front];
	}
	//enqueue
	void enqueue(T data) {

		if (!full()) {
			this->rear = (this->rear + 1) % this->ms;
			this->arr[this->rear] = data;
			this->cs += 1;
		}
	}
	//dequeue
	void dequeue() {
		if (!empty()) {
			this->front = (this->front + 1) % this->ms;
			this->cs -= 1;
		}
	}
};
int main() {

	Queue<int> q(10);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	while (!q.empty()) {
		cout << q.getFront() << " ";
		q.dequeue();
	}

	cout << endl;

	Queue<string> qs(5);

	qs.enqueue("Tushar");
	qs.enqueue("Bunty");
	qs.enqueue("Parag");
	qs.enqueue("Nikhil");
	qs.enqueue("Suhail");

	while (!qs.empty()) {
		cout << qs.getFront() << endl;
		qs.dequeue();
	}
	return 0;
}