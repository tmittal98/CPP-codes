#include <iostream>
#include <vector>
using namespace std;

class  Heap {
	vector<int> v;
	bool minHeap;

	bool compare(int a, int b) {
		if (minHeap) {
			return a > b;
		}
		else {
			return b > a;
		}
	}

	void heapify(int idx) {

		int left = 2 * idx;
		int right = left + 1;

		int min_idx = idx;
		int last = v.size() - 1;

		if (left <= last and compare(v[idx], v[left]) ) {
			min_idx = left;
		}

		if (right <= last and compare(v[min_idx], v[right]) ) {
			min_idx = right;
		}

		if (min_idx != idx) {
			swap(v[min_idx], v[idx]);
			heapify(min_idx);
		}

		return;

	}
public:
	Heap(int default_size = 10, bool type = true) {
		v.reserve(default_size);
		v.push_back(-1);//blocking 0th index
		minHeap = type;
	}

	void push(int data) {
		v.push_back(data);
		int idx = v.size() - 1;
		int parent = idx / 2;

		while (idx > 1 and compare(v[parent], v[idx]) ) {
			swap(v[parent], v[idx]);
			idx = parent;
			parent = parent / 2;
		}
	}

	int top() {
		return v[1];
	}

	bool empty() {
		return v.size() == 1;
	}

	void pop() {

//Step 1 swap v[0] and last element
		int last = v.size() - 1;

		swap(v[1], v[last]);

//Step 2 Remove the last element
		v.pop_back();

//Step 3 heapify()
		heapify(1);
	}
};

int main() {

	int n; cin >> n;
	bool type; cin >> type;

	Heap h(n, type);

	for (int i = 0; i < n; i++) {
		int no; cin >> no;
		h.push(no);
	}

	while (!h.empty()) {
		cout << h.top() << " ";
		h.pop();
	}
	return 0;
}
