#include <list>
#include <utility>
#include <iostream>

using namespace std;

int main() {

	list<pair<int, int>> *l;

	int n;
	cout << "Enter no of vertices\n";
	cin >> n;

	l = new list<pair<int, int>>[n];

	int e;
	cout << "Enter no of edges\n";
	cin >> e;

	for (int i = 0; i < e; ++i)
	{
		cout << "enter the both nodes of edge and weight of the edge\n";
		int x, y, w;
		cin >> x >> y >> w;

		l[x].push_back(make_pair(y, w));
		l[y].push_back(make_pair(x, w));
	}

	//print the adjacency list

	for (int i = 0; i < n; ++i)
	{
		list<pair<int, int>> li = l[i];

		cout << "Linked List " << i << " -> ";
		for (auto ele : li) {
			cout << "(" << ele.first << "," << ele.second << ") ->";
		}
		cout << endl;

	}

}