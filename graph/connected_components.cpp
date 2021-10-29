// Program to count Number of connected components in an undirected graph
#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>> adjList;
        
        void addEdge(int x,int y){
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        
        void dfs(int src,unordered_map<int,bool> &visited){
            
            visited[src] = true;
            
            for(auto nbr: adjList[src]){
                if(!visited[nbr]){
                    dfs(nbr,visited);
                }
            }
            return;
        }
        int connectedComponents(){
            
            unordered_map<int,bool> visited;
            
            for(auto node_pair : adjList){
                visited[node_pair.first] = false;
            }
            
            int count = 0;
            
            for(auto node_pair : visited){
                int node = node_pair.first;
                if(!visited[node]){
                    count++;
                    dfs(node,visited);
                }
            }
            return count;
        }
};

int main() {
	
    Graph g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);
    
    g.addEdge(5,6);

    g.addEdge(7,7);
	
	cout<<g.connectedComponents();
	return 0;
}