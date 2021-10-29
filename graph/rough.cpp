#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int> *l;

    public:
    
    Graph(int v){
        this->v = v;
        this->l = new list<int>[v];
    }

    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAdjList(){

        for (int i = 0; i < v;i++){
            cout << "Vertex " << i << " : ";
            for(auto nbr : l[i]){
                cout << nbr << "->";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.printAdjList();

    return 0;
}
// C:\Users\tusha\Documents\cpp codes\graph\rough.cpp