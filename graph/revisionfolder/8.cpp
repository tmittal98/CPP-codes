//Topological Sorting using DFS 
//DAC
#include<bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<int, list<int>> adjList;
    public:
        void addEdge(int src,int dest){
            adjList[src].push_back(dest);
        }

        void dfs_helper(int node,unordered_map<int,bool> &visited,list<int>&ordering){

            visited[node] = true;

            for (auto nbr : adjList[node]){
                if(!visited[nbr]){
                    dfs_helper(nbr, visited, ordering);
                }
            }

            ordering.push_front(node);
        }
        void topoSort(){    

            unordered_map<int, bool> visited;
            list<int> ordering;

            for(auto node_pair : adjList){
                int node = node_pair.first;
                visited[node] = false;
            }

            for(auto node_pair : adjList){
                int node = node_pair.first;

                if(!visited[node]){
                    dfs_helper(node, visited, ordering);
                }
            }

            for(auto node : ordering){
                cout << node << "->";
            }
            cout << endl;
        }
};
int main(){

    Graph g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.addEdge(4, 5);
    g.addEdge(6, 5);

    g.topoSort();
    return 0;
}
