//DFS
#include<bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<int, list<int>> adjList;

    public:

    void addEdge(int src,int dest,bool bidir = true){
        adjList[src].push_back(dest);
        if(bidir){
            adjList[dest].push_back(src);
        }
    }

    void printAdjList(){    

        for(auto node_pair : adjList){
            int node = node_pair.first;
            cout << "Node " << node << " -> ";
            for(auto nbr : adjList[node]){
                cout << nbr << "->";
            }
            cout << endl;
        }
    }   
    void dfs_helper(int node,unordered_map<int,bool> &visited){
        //mark the curr node as visited and print
        visited[node] = true;
        cout << node << ",";

        for(auto nbr : adjList[node]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited);
            }
        }
    }
    void dfs(int src){

        unordered_map<int, bool> visited;

        for(auto node_pair: adjList){
            int node = node_pair.first;
            visited[node] = false;
        }

        dfs_helper(src, visited);
    }
};
int main(){

    Graph g;

    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.dfs(0);
    return 0;
}