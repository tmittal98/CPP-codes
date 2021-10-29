#include <iostream>
#include <stack>

using namespace std;

void transfer(stack<int> &a, stack<int> &b) {

	while (!a.empty()) {
		b.push(a.top());
		a.pop();
	}
	return;
}

void transferUtil(stack<int> &a, stack<int> &b, int n) {

	for (int i = 0; i < n; i++) {
		b.push(a.top());
		a.pop();
	}
	return;
}

void insertAtBottom(stack<int> &s, int topele) {

	//base case
	if (s.empty()) {
		s.push(topele);
		return;
	}

	int ele = s.top();
	s.pop();

	insertAtBottom(s, topele);

	s.push(ele);
	return;

}
void reverse(stack<int> &s) {

	//base case
	if (s.empty()) {
		return;
	}

	int topele = s.top();
	s.pop();

	reverse(s);

	insertAtBottom(s, topele);
}
int main() {

	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	//Approach using 2 stack

	// stack<int> s1, s2;

	// transfer(s, s1);
	// transfer(s1, s2);
	// transfer(s2, s);

	//Approach using 1 stack
	// stack<int> helper;
	// int n = s.size();

	// for (int i = 0; i < n - 1; ++i)
	// {
	// 	//store the top element and pop it
	// 	int x = s.top();
	// 	s.pop();

	// 	transferUtil(s, helper, n - i - 1);

	// 	s.push(x);

	// 	transferUtil(helper, s, n - i - 1);

	// }

	//Approach 3 using recursion
	reverse(s);
	// insertAtBottom(s, 10);

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}