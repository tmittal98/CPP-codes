//Topological Sorting using bfs
#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>> adjList;
        
        void addEdge(int x,int y){
            adjList[x].push_back(y);
        }
        
        void topoSort(){
            
            unordered_map<int,int> indegree;
            
            for(auto node_pair : adjList){
                int node = node_pair.first;
                indegree[node] = 0;
            }
            
            for(auto node_pair : adjList){
                for(auto nbr : adjList[node_pair.first]){
                    indegree[nbr]++;   
                }
            }
            
            queue<int> q;
            
            for(auto node_pair : indegree){
                int node = node_pair.first;
                if(indegree[node] == 0){
                    q.push(node);
                }
            }
            
            while(!q.empty()){
                
                int node = q.front();
                q.pop();
                
                cout<<node<<" ";
                
                for(auto nbr : adjList[node]){
                    indegree[nbr]--;
                    if(indegree[nbr] == 0){
                        q.push(nbr);
                    }
                }
            }
            return;
        }
        
};

int main() {
	
    Graph g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(5,2);
    
    g.topoSort();
	return 0;
}