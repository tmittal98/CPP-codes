#include <iostream>

using namespace std;

void permutations(char in[], int i) {

	//base case
	if (in[i] == '\0') {
		cout << in << " ";
		return;
	}

	for (int j = i; in[j] != '\0'; j++) {

		//swap
		swap(in[i], in[j]);
		permutations(in, i + 1);

		//Backtracking => to restore the original array
		// swap(in[i], in[j]);
	}
}

int main() {

	char in[10];
	cin >> in;

	permutations(in, 0);
	cout << endl << in << endl;
	return 0;
}