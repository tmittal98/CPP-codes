//SSSP in unweighted graph
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<T>> adjList;

    public:
        void addEdge(T src,T dest,bool bidir = true){
            adjList[src].push_back(dest);
            if(bidir){
                adjList[dest].push_back(src);
            }
        }   

        void sssp(T src){

            queue<T> q;
            unordered_map<T, int> dist;

            //dist map src->0 and all other nodes we have to keep dist->inf
            //iterate over the hashmap and add all the nodes in dist
            for(auto node_pair : adjList){
                T node = node_pair.first;
                dist[node] = INT_MAX;
            }
            q.push(src);
            dist[src] = 0;

            while(!q.empty()){

                T node = q.front();
                q.pop();

                //iterte over all the unvisited nbrs
                for(auto nbr : adjList[node]){  
                    if(dist[nbr] == INT_MAX){
                        dist[nbr] = dist[node] + 1;
                        q.push(nbr);
                    }
                }
            }

            //print the shortest distance from src
            //iterate over the dist map and print
            for(auto dist_pair : dist){
                T node = dist_pair.first;
                int dist = dist_pair.second;
                cout << "Distance from " << src << " to " << node << " is " << dist << endl;
            }

        }
        void printAdjList(){
            //iterate over the hashmap
            for(auto node_pair: adjList){
                T node = node_pair.first;
                cout << "Node " << node << " -> ";
                    for(auto nbr : adjList[node]){
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
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(5, 4);

    g.printAdjList();

    g.sssp(0);

    return 0;
}