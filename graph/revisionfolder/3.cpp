//BFS 
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<T>> adjList;
    public:
        void addEdge(T x,T y,bool bidir= true){
            adjList[x].push_back(y);
            if(bidir){
                adjList[y].push_back(x);
            }
        }   
        
        void bfs(T src){

            queue<T> q;
            unordered_map<T, bool> visited;

            //add all the nodes in the hashmap (visited ) and mark it as false
            for(auto node_pair : adjList){
                T node = node_pair.first;
                visited[node] = false;
            }

            visited[src] = true;
            q.push(src);

            while(!q.empty()){

                T node = q.front();
                q.pop();

                cout << node << ",";

                for(auto nbr : adjList[node]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
        }
        void printAdjList(){
            
            //iterate over the hashmap
            for(auto node_pair : adjList){
                T node = node_pair.first;
                cout << "Node " << node << " -> ";
                list<T> nbrs = node_pair.second;

                for(auto nbr : nbrs){
                    cout << nbr << "->";
                }
                cout << endl;
            }

        }
};

int main(){

    Graph<int> g;

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(5, 4);

    g.printAdjList();

    g.bfs(0);

    return 0;   
}