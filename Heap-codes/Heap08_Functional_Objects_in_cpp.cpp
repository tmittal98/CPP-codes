#include <iostream>
#include <cstring>

using namespace std;

class Fun {

public:
	void operator()() {
		cout << "Having fun with myself"<<endl;
	}

	void operator()(string s) {
		cout << "Having fun with " << s;
	}
};
int main() {

	Fun f;
	f(); //Functor
	f("Tushar"); //Functor
	return 0;
}