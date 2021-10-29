//Detect Cycle in Directed Graph
//DFS + check the nbr is in curr path
#include<bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<int,list<int>> adjList;
    public:
        void addEdge(int src,int dest){
            adjList[src].push_back(dest);
        }
        bool is_tree_helper(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&path){

            visited[node] = true;
            path[node] = true;

            for(auto nbr : adjList[node]){

                if(path[nbr]){
                    //Back edge
                    return false;
                }
                else if(!visited[nbr]){
                    bool dfs_call = is_tree_helper(nbr, visited, path);
                    if(dfs_call == false){
                        return false;
                    }
                }
            }
            path[node] = false;
            return true;
        }

        bool is_tree(){

        //Detect Back Edge
        //Keep track of the current path
        unordered_map<int, bool> visited;
        unordered_map<int, bool> path;

        for(auto node_pair : adjList){
            int node = node_pair.first;
            visited[node] = false;
            path[node] = false;
        }

        for(auto node_pair : adjList){
            int node = node_pair.first;

            if(!visited[node]){
                return is_tree_helper(node, visited, path);
            }
        }

            return true;
        }
};
int main(){

    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 5);
    g.addEdge(5, 6);
    g.addEdge(1, 5);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 2);//Back Edge

    if(g.is_tree()){
        cout << "The graph is a tree" << endl;
    }
    else{
        cout << "The graph is not a tree" << endl;
    }
    return 0;
}