//Check if a given undirected graph is tree or not using bfs
#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>> adjList;
        
        void addEdge(int x,int y){
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        
        bool isTree(){
            
            unordered_map<int,bool> visited;
            unordered_map<int,int> parent;
            
            for(auto node_pair : adjList){
                int node = node_pair.first;
                visited[node] = false;
                parent[node] = node;
            }
            
            int srcNode = 0;
            visited[srcNode] = true;
            parent[srcNode] = srcNode;
            
            queue<int> q;
            q.push(srcNode);
            
            while(!q.empty()){
                
                int node = q.front();
                q.pop();
                
                for(auto nbr : adjList[node]){
                    
                    if(visited[nbr] and parent[node] != nbr){
                        return false;
                    }
                    else if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] = true;
                        parent[nbr] = node;
                    }
                }
            }
            
            return true;
        }
        
};

int main() {
	
    Graph g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);
    
    if(g.isTree()){
        cout<<"The graph is tree\n";
    }
    else{
        cout<<"The graph is not a tree\n";
    }
    
	return 0;
}