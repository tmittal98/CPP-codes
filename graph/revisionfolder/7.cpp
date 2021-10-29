//Connected components in dfs graph
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

        visited[node] = true;

        for(auto nbr : adjList[node]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited);
            }
        }
    }
    void dfs(){

        unordered_map<int, bool> visited;

        for(auto node_pair : adjList){
            int node = node_pair.first;
            visited[node] = false;
        }

        int count = 0;

        for(auto node_pair : adjList){
            int node = node_pair.first;
            if(!visited[node]){
                count++;
                dfs_helper(node, visited);
            }
        }

        cout<<"The no of connected components are "<<count<<endl;
    }
};
int main(){

    Graph g;

    g.addEdge(1, 2);
    g.addEdge(1, 3);

    g.addEdge(4,5);
    g.addEdge(5,6);

    g.addEdge(7,8);
    g.addEdge(8,9);

    g.dfs();
    
    return 0;
}
