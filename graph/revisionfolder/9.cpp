//Topological Sort using BFS
//DAC
#include<bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<int, list<int>> adjList;

    public:

    void addEdge(int src,int dest){
        adjList[src].push_back(dest);
    }

    void toposort(){

        unordered_map<int, int> indegree;
    
         for(auto node_pair : adjList){
            int node = node_pair.first;
            indegree[node] = 0;
        }

        for (auto node_pair : adjList){
            int node = node_pair.first;
            for(auto nbr : adjList[node]){
                indegree[nbr]++;
            }    
        }

        queue<int> q;
        
        for(auto node_pair : adjList){
            int node = node_pair.first;
            if(indegree[node] == 0){
                q.push(node);
            }
        }

        while(!q.empty()){

            int node = q.front();
            q.pop();

            cout<<node<<"->";

            for(auto nbr : adjList[node]){
                indegree[nbr]--;    
                    if(indegree[nbr] == 0){
                        q.push(nbr);
                    }
            }
        }
    }
};

int main(){

    Graph g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.addEdge(4, 5);
    g.addEdge(6, 5);

    g.addEdge(7, 8);

    g.toposort();

    return 0;
}