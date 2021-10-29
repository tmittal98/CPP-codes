#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph{
    unordered_map<string, list<pair<string, int>>> mp;
public:
    void addEdge(string city1,string city2,bool bidir,int dist){
        mp[city1].push_back({city2, dist});

        if(bidir){
            mp[city2].push_back({city1, dist});
        }
    }
    void printAdjList(){
       for(auto c : mp){
           string city = c.first;
           cout << "city " << city << " -> ";
           list<pair<string, int>> nbrs = mp[city];
           for(auto nbr : nbrs){
               string dest = nbr.first;
               int dist = nbr.second;
               cout << "[" << dest << "," << dist << "],";
           }
           cout << endl;
       }
    }
};
int main(){
    Graph g;
    g.addEdge("A","B",0,10);
    g.addEdge("A","C",0,15);
    g.addEdge("C","D",1,10);
    g.addEdge("D","B",1,30);
    g.addEdge("A","D",1,20);
    g.printAdjList();
    return 0;
}

/*                          10
                        A------->B
                        |\       | 
                        | \      |
                        |  \20   |30
                      15|   \    |
                        |    \   |
                        |     \  |
                        \/     \ |
                        C--------D
                            10 
*/