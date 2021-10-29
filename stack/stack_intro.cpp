#include<iostream>
#include<vector>

using namespace std;


template<typename t>
class stack {
private:
	vector<t> v;
public:

	//insert
	void push(t data) {
		v.push_back(data);
	}
	//delete
	void pop() {
		if (!empty()) {
			v.pop_back();
		}
	}
	//empty
	bool empty() {
		return v.size() == 0;
	}
	//top
	t top() {
		return v[v.size() - 1];
	}

};
int main() {

	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	stack<char> s1;

	s1.push('a');
	s1.push('b');
	s1.push('c');
	s1.push('d');

	while (!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	}
	return 0;
}