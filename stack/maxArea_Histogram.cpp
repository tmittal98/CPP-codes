#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
class stack {

private :
	vector<T> v;

public:
	//push
	void push(T data) {
		v.push_back(data);
	}
	//pop
	void pop() {
		v.pop_back();
	}
	//empty
	bool empty() {
		return v.size() == 0;
	}
	//top
	T top() {
		return v[v.size() - 1];
	}

};

vector<int> findIdxNearestSmallestToRight(int arr[], int n) {

	stack<pair<int, int>> helper;
	vector<int> v;

	for (int i = n - 1; i >= 0; i--) {

		//stack empty
		if (helper.empty()) {
			v.push_back(n);
		}
		else {

			if (!helper.empty() and helper.top().first < arr[i]) {
				v.push_back(helper.top().second);
			}
			else {
				while (!helper.empty() and helper.top().first >= arr[i]) {
					helper.pop();
				}
				if (helper.empty()) {
					v.push_back(n);
				}
				else {
					v.push_back(helper.top().second);
				}
			}
		}
		helper.push(make_pair(arr[i], i));
	}

	reverse(v.begin(), v.end());
	return v;
}

vector<int> findIdxNearestSmallestToLeft(int arr[], int n) {

	stack<pair<int, int>> helper;
	vector<int> v;

	for (int i = 0; i < n; i++) {

		//stack empty
		if (helper.empty()) {
			v.push_back(-1);
		}
		else {

			if (!helper.empty() and helper.top().first < arr[i]) {
				v.push_back(helper.top().second);
			}
			else {
				while (!helper.empty() and helper.top().first >= arr[i]) {
					helper.pop();
				}
				if (helper.empty()) {
					v.push_back(-1);
				}
				else {
					v.push_back(helper.top().second);
				}
			}
		}
		helper.push(make_pair(arr[i], i));
	}

	return v;
}


int main() {

	/*algo
	1.find index of nearest smallest to right
		stack right to left
		if stack empty 7 push
		reverse
	2.find nearest smallest to left index
	3.diff of Ir - Il -1
	4.area = diff*height
	5.maximum area
	*/

	int arr[] = {6, 2, 5, 4, 5, 1, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	vector<int> right = findIdxNearestSmallestToRight(arr, n);
	vector<int> left = findIdxNearestSmallestToLeft(arr, n);

	int maxArea = INT_MIN;

	for (int i = 0; i < right.size(); i++) {
		right[i] = (right[i] - left[i] - 1) * arr[i];
		maxArea = max(maxArea, right[i]);
	}
	cout << maxArea;

	return 0;
}