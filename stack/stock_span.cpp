#include <iostream>
#include <vector>

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
vector<int> fiIdxNxtGreaterEleToLeft(int arr[], int n) {

	stack<pair<int, int>> helper;
	vector<int> v;

	for (int i = 0; i < n; i++) {

		//stack empty
		if (helper.empty()) {
			v.push_back(-1);
		}
		else {
			//stack top element greater then push top element
			if (!helper.empty() and helper.top().first > arr[i]) {
				v.push_back(helper.top().second);
			}
			else {
				while (!helper.empty() and helper.top().first <= arr[i]) {
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

	int arr[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(arr) / sizeof(arr[0]);

	vector<int> v = fiIdxNxtGreaterEleToLeft(arr, n);

	for (int i = 0; i < n; i++) {
		v[i] = i - v[i];
	}

	for (vector<int>::iterator it = v.begin(); it != v.end() ; it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;

}