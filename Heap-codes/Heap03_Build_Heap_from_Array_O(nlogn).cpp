#include <iostream>
#include <vector>
using namespace std;

void buildMaxHeap(vector<int> &v) {

	for (int i = 2; i < v.size() ; i++) {
		int idx = i;
		int parent = i / 2;

		while (idx > 1 and v[idx] > v[parent]) {
			swap(v[idx], v[parent]);
			idx = parent;
			parent = parent / 2;
		}
	}
	return;
}


int main() {

	vector<int> v{23, 12, 56, 76, 87, 90, 34};

	buildMaxHeap(v);

	for (auto x : v) {
		cout << x << " ";
	}

	return 0;
}