#include <bits/stdc++.h>
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
};


int main() {

	return 0;
}