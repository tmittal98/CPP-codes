//Detect cycle in an undirected Graph
#include<bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<int, list<int>> adjList;  
    public:
    void addEdge(int src,int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
    bool bfs(int node, unordered_map<int,bool>& visited,unordered_map<int,int>& parent){
    //BFS traversal 
        queue<int> q;

        q.push(node);

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto nbr : adjList[node]){

                if(visited[nbr] == true and parent[node] != nbr){
                    return true;
                }
                else if(!visited[nbr]){ 
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return false;
    }


    bool is_cycle_present(){
    
    //Try to find if a node is visited via more than one path i.e. it is visited by multiple path
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    for(auto node_pair : adjList){
        int node = node_pair.first;
        visited[node] = false;
        parent[node] = node;
    }

    for(auto node_pair : adjList){
        int node = node_pair.first;
        if(!visited[node]){
            if(bfs(node, visited, parent))
                return true;
        }
    }

    return false;
    }
};
int main(){

    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    if(g.is_cycle_present()){
        cout << "The graph is not tree" << endl;
    }
    else{
        cout << "The graph is tree" << endl;
    }
    return 0;
}