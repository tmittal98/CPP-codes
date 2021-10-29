#include <iostream>
#include <vector>

using namespace std;

//1 is minHeap and 0 is maxHeap

bool compare(int a, int b, bool type) {

	if (type) {
		return a < b;
	}
	else {
		return a > b;
	}
}
void heapify(vector<int> &v, int idx, bool type) {

	int last = v.size() - 1;
	int left = 2 * idx;
	int right = left + 1;
	int min_idx = idx;

	if (left <= last and compare(v[left], v[idx], type) ) {
		min_idx = left;
	}

	if (right <= last and compare(v[right], v[min_idx], type) ) {
		min_idx = right;
	}

//base case for recursion
	if ( min_idx != idx) {
		swap(v[min_idx], v[idx]);
		heapify(v, min_idx, type);
	}
}

void buildHeapOptimised(vector<int> &v, bool type) {

//Start iterating from last non-leaf node which is N/2
	for (int i = (v.size() - 1) / 2 ; i >= 1 ; i--) {
		heapify(v, i, type);
	}
}


int main() {

	vector<int> v{ -1, 34, 65, 12, 87, 90, 78, 3, 47};

	bool type = false;

	buildHeapOptimised(v, type);

	for (auto x : v) {
		cout << x << " ";
	}

	return 0;
}