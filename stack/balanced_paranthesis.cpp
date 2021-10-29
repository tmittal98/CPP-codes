#include <iostream>
#include<stack>
#include <string>
using namespace std;

bool checkexpression(string exp) {

	stack<int> s;

	for (char c : exp) {

		if (c == '(') {
			s.push(c);
		}
		else if (c == ')') {
			if (s.empty() or s.top() != '(') {
				return false;
			}
			//s.top must be opening
			else {
				s.pop();
			}
		}
	}

	return s.empty();
}
int main() {

	string exp;
	cin >> exp;

	bool valid = checkexpression(exp);
	if (valid) {
		cout << "exp is valid";
	}
	else {
		cout << "expis not valid";
	}
}