#include <bits/stdc++.h>
using namespace std;

class Graph{
   map<char,list<pair<char,int>>> umap;
    public:
        void addEdge(char src,char dest,int wght,bool bidir = true){
            umap[src].push_back(make_pair(dest, wght));
            if(bidir){
                umap[dest].push_back(make_pair(src, wght));
            }
        }

        void printAdjList(){

            //iterate over the hashmap
            for(auto node_pair : umap){

                char node = node_pair.first;
                list<pair<char, int>> nbrs = node_pair.second;

                cout << "Node " << node << " -> ";

                for(auto nbr : nbrs){
                    char dest_node = nbr.first;
                    int cost = nbr.second;
                    cout << "(" << dest_node << "," << cost << ")->";
                }
                cout << endl;
            }
        }

};

int main(){

    Graph g;

    g.addEdge('a','b', 20);
    g.addEdge('a','d', 50, false);
    g.addEdge('a','c', 10);
    g.addEdge('b','d', 30);
    g.addEdge('c','d', 40);

    g.printAdjList();

    return 0;
}