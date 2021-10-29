#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph{
    
    public:
        unordered_map<int,list<int>> l;
        
        void addEdge(int x,int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        
        void dfs_helper(int src,unordered_map<int,bool> &visited){
            
            cout<<src<<" ";
            visited[src] = true;
            
            //for all the nbrs of src call dfs_helper which are not visited
            for(auto nbr : l[src]){
                if(!visited[nbr]){
                    dfs_helper(nbr,visited);
                }
            }
            return;
        }
        void dfs(int src){
            
            unordered_map<int,bool> visited;
            
            for(auto node_pair : l){
                visited[node_pair.first] = false; 
            }
            
            dfs_helper(src,visited);
        }
};
int main() {
	Graph g;
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(3,2);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.dfs(0);
	return 0;
}