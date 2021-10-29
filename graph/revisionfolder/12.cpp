//Detect Cycle in an undirected graph using DFS
#include<bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<int, list<int>> adjList;
    public:
    void addEdge(int x,int y){
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    bool is_tree_helper(int node,unordered_map<int,bool>&visited,int parent){

        visited[node] = true;

        for(auto nbr : adjList[node]){
            if(nbr != parent and visited[nbr]){
                return false;
            }
            else if(!visited[nbr]){

                bool kya_tree_hain = is_tree_helper(nbr, visited, node);
                if(kya_tree_hain == false){
                    return false;
                }
            }
        }
        return true;
    }
    bool is_tree(){

        unordered_map<int, bool> visited;
        for(auto node_pair : adjList){
            int node = node_pair.first;
            visited[node] = false;
        }

        for (auto node_pair : adjList){
            int node = node_pair.first;
            if(!visited[node]){
                int parent = node;
                if(is_tree_helper(node,visited,parent) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 2);
    g.addEdge(4, 5);

    if(g.is_tree()){
        cout << "The graph is tree" << endl;
    }
    else{
        cout << "The Graph is not a tree" << endl;
    }
    return 0;
}