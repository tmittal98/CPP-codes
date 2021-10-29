#include <iostream>
#include <vector>

using namespace std;

//1 = minHeap
//0 = maxHeap

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

	if (right <= last and compare(v[right], v[min_idx] , type)) {
		min_idx = right;
	}

//base case for heapification

	if (min_idx != idx) {
		swap(v[min_idx], v[idx]);
		heapify(v, min_idx, type);
	}
}

void buildHeap(vector<int> &v, bool type) {

	//iterating from last non-leaf node and heapifying at each iteration

	for (int i = (v.size() - 1) / 2 ; i >= 1; i--) {
		heapify(v, i, type);
	}
}

void heapifyIn(vector<int> &v, int idx, bool type, int size) {

	int last = size;
	int left = 2 * idx;
	int right = left + 1;
	int min_idx = idx;

	if (left <= last and compare(v[left], v[idx], type) ) {
		min_idx = left;
	}

	if (right <= last and compare(v[right], v[min_idx], type)) {
		min_idx = right;
	}

	//base case
	if (min_idx != idx) {
		swap(v[idx], v[min_idx]);
		heapifyIn(v, min_idx, type, size);
	}

}
vector<int> heapSort(vector<int> &v) {

	v.push_back(-1);
	swap(v[0], v[v.size() - 1]);

	vector<int> result;

	bool type = true;
	//buildHeap from Array
	buildHeap(v, type);

	cout << "Min Heap " << endl;
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
	//extract each element and heapify that element

	int n = v.size() - 1;

	while (n--) {
		int ele = v[1];
		result.push_back(ele);
		int last = v.size() - 1;
		swap(v[1], v[last]);
		v.pop_back();
		heapifyIn(v, 1, type, n);
	}

	return result;
}
int main() {
	vector<int> v{ 54, 12, 74, 21, 73, 24, 6, 25, 64};

	vector<int> res = heapSort(v);

	for (auto x : res) {
		cout << x << " ";
	}
	return 0;
}
