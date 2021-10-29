#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class stack {
private:
	vector<T> v;
public:
	//push
	void push(T data) {
		v.push_back(data);
		return;
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

vector<int> findNextGreaterToLeft(int arr[], int n) {

	stack<int> helper;
	vector<int> v;

	for (int i = 0; i < n ; i++) {

		//stack empty
		if (helper.empty()) {
			v.push_back(-1);
		}
		else {
			//stack.top() > arr[i]
			if (!helper.empty() and helper.top() > arr[i]) {
				v.push_back(helper.top());
			}
			//stack.top() < arr[i]
			else if (!helper.empty() and helper.top() <= arr[i]) {

				while (!helper.empty() and helper.top() <= arr[i]) {
					helper.pop();
				}

				if (helper.empty()) {
					v.push_back(-1);
				}
				else {
					v.push_back(helper.top());
				}
			}
		}
		helper.push(arr[i]);
	}

	return v;
}

vector<int> findNextGreaterToRight(int arr[], int n) {

	stack<int> helper;
	vector<int> v;

	for (int i = n - 1; i >= 0; i--) {

		//stack empty
		if (helper.empty()) {
			v.push_back(-1);
		}
		//stack not empty
		else {
			if (!helper.empty() and helper.top() > arr[i]) {
				//push in vector
				v.push_back(helper.top());
			}
			else {
				while (!helper.empty() and helper.top() <= arr[i]) {
					helper.pop();
				}
				if (helper.empty()) {
					v.push_back(-1);
				}
				else {
					v.push_back(helper.top());
				}
			}
		}
		helper.push(arr[i]);
	}

	reverse(v.begin(), v.end());

	return v;
}

vector<int> findNextSmallerToLeft(int arr[], int n) {

	stack<int> helper;
	vector<int> v;

	for (int i = 0; i < n; ++i)
	{
		if (helper.empty()) {
			v.push_back(-1);
		}
		else {

			if (!helper.empty() and helper.top() < arr[i]) {
				v.push_back(helper.top());
			}
			else {
				while (!helper.empty() and helper.top() >= arr[i]) {
					helper.pop();
				}
				if (helper.empty()) {
					v.push_back(-1);
				}
				else {
					v.push_back(helper.top());
				}
			}
		}
		helper.push(arr[i]);
	}

	return v;
}

vector<int> findNextSmallerToRight(int arr[], int n) {

	stack<int> helper;
	vector<int> res;

	for (int i = n - 1; i >= 0; i--) {

		//stack empty
		if (helper.empty()) {
			res.push_back(-1);
		}
		else {
			//stack is not empty

			if (!helper.empty() and helper.top() < arr[i]) {
				//just push it in the vector
				res.push_back(helper.top());
			}
			else {
				//pop untill either the stack is empty or smaller element is achieved
				while (!helper.empty() and helper.top() >= arr[i]) {
					helper.pop();
				}
				//if stack empty then push -1 in the vector else top element
				if (helper.empty()) {
					res.push_back(-1);
				}
				else {
					res.push_back(helper.top());
				}
			}
		}
		helper.push(arr[i]);
	}

	reverse(res.begin(), res.end());
	return res;
}

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

	int arr[] = {1, 5, 3, 2, 4, 8};

	vector<int> ngl = findNextGreaterToLeft(arr, 6);
	vector<int> ngr = findNextGreaterToRight(arr, 6);
	vector<int> nsl = findNextSmallerToLeft(arr, 6);
	vector<int> nsr = findNextSmallerToRight(arr, 6);

	for (vector<int>::iterator it = ngl.begin() ; it != ngl.end() ; it++) {
		cout << *it << " ";
	}

	cout << endl;

	for (vector<int>::iterator it = ngr.begin() ; it != ngr.end() ; it++) {
		cout << *it << " ";
	}

	cout << endl;

	for (vector<int>::iterator it = nsl.begin() ; it != nsl.end() ; it++) {
		cout << *it << " ";
	}

	cout << endl;

	for (vector<int>::iterator it = nsr.begin() ; it != nsr.end() ; it++) {
		cout << *it << " ";
	}

	cout << endl;


	//Find indexes of these above elements

	vector<int> ngli = fiIdxNxtGreaterEleToLeft(arr, 6);

	for (vector<int>::iterator it = ngli.begin() ; it != ngli.end() ; it++) {
		cout << *it << " ";
	}
	return 0;
}