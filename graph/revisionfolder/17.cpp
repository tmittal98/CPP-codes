//Prims's Algo
//Greedy Algo to find MST
//MST SET
//ACTIVE EDGES
#include <bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<int,list<pair<int,int>>> adjList;

    public:
        void addEdge(int x,int y,int wgt){
            adjList[x].push_back({y, wgt});
            adjList[y].push_back({x, wgt});
        }
        
        void printGraph(){

            for(auto node_pair : adjList){
                cout << "Node " << node_pair.first << " -> ";
                for(auto nbr_pair : node_pair.second){
                    int nbr = nbr_pair.first;
                    int w = nbr_pair.second;
                    cout << "(" << nbr << "," << w << ") -> ";
                }
                cout << endl;
            }
        }
        int prims_mst(int src){
            //start from a src 
            //add all the nbrs with wght if the nbrs are not in mst set
            //min heap build to store {wght,node} priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>  
            //start {0,0} mark 0 as visited

            unordered_map<int, bool> visited;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            
            //(wght,node)
            pq.push({0, src});

            for(auto node_pair : adjList){
                int node = node_pair.first;
                visited[node] = false;
            }
            int cost = 0;
            while(!pq.empty()){

                pair<int, int> pq_top = pq.top();
                pq.pop();

                int wght = pq_top.first;
                int vertex = pq_top.second;

                if(visited[vertex]){
                    continue;
                }
                cost += wght;
                visited[vertex] = true;
                
                for(auto nbr_pair : adjList[vertex]){
                    int nbr = nbr_pair.first;
                    int wt = nbr_pair.second;
                        if(!visited[nbr]){
                            pq.push({wt, nbr});
                        }
                }
            }
            return cost;
        }
};
int main(){

    Graph g;

    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 3, 9);
    g.addEdge(4, 2, 8);
    g.addEdge(4, 5, 7);
    g.addEdge(3, 5, 3);
    g.addEdge(3, 6, 1);
    g.addEdge(5, 6, 3);
    g.addEdge(4, 6, 10);
    g.addEdge(4, 8, 5);
    g.addEdge(4, 7, 8);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 9);
    g.addEdge(8, 9, 11);
    g.addEdge(7, 9, 2);

    g.printGraph();

    cout << "The cost of MST is " << g.prims_mst(1) << endl;

    return 0;
}