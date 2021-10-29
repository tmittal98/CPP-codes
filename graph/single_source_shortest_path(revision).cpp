#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <climits>
using namespace std;

class Graph{
    
    public:
        unordered_map<int,list<int>> l;
        
        void addEdge(int x,int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void shortestPath(int src){
            
            unordered_map<int,int> dist;
            queue<int> q;
            
            q.push(src);
        
            //for all nodes we have to make the dist from src as INF
            for(auto node_pair : l){
                int vertex = node_pair.first;
                dist[vertex] = INT_MAX;
            }
            dist[src] = 0;
            
            while(!q.empty()){
                
                int node = q.front();
                q.pop();
                
                for(auto nbr : l[node]){
                    if(dist[nbr] == INT_MAX){
                        dist[nbr] = dist[node] + 1;
                        q.push(nbr);
                    }
                }
            }
            
            for(auto node : dist){
                cout<<"Distance from src 0 to "<<node.first<<" is "<<node.second<<endl;
            }
            
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
	g.shortestPath(0);
	return 0;
}