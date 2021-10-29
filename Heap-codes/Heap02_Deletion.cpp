#include <iostream>
#include <vector>
using namespace std;

class Heap {
	vector<int> v;
	bool minHeap;

	bool compare(int a, int b) {

		if (minHeap) {
			return a < b;
		}
		return b < a;
	}

	void heapify(int idx) {

		int left = 2 * idx;
		int right = left + 1;

		int min_idx = idx;
		int last = v.size() - 1;

		if (left <= last and compare(v[left], v[idx])) {

			min_idx = left;
		}

		if (right <= last and compare(v[right], v[min_idx])) {

			min_idx = right;

		}

		if (min_idx != idx) {

			swap(v[idx], v[min_idx]);
			heapify(min_idx);
		}
	}
public:
	Heap(int default_size = 10, bool type = true) {
		v.reserve(default_size);
		v.push_back(-1);//Block 0th index
		minHeap = type;
	}

	void push(int data) {

		v.push_back(data);

		int idx = v.size() - 1; //Index at which element is pushed
		int parent = idx / 2;

		//Keep pushing to the top till we reach root node or stop midway if the data is greater than parent element
		while (idx > 1 and compare(v[idx], v[parent])) {

			swap(v[idx], v[parent]);

			idx = parent;
			parent = parent / 2;
		}
	}

	int top() {
		return v[1];
	}

	void pop() {
		
		int last = v.size() - 1;
		//Swap first and last node
		swap(v[1], v[last]);

		//Remove last element
		v.pop_back();

		//Heapify to restore heap
		heapify(1);

	}

	bool empty() {
		return v.size() == 1;
	}
};


int main() {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	Heap h(false);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {

		int no; cin >> no;
		h.push(no);
	}

	//remove all the elements one by one

	while (!h.empty()) {

		cout << h.top() << " ";
		h.pop();

	}

	return 0;
}