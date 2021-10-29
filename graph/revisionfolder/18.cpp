//Bellman Ford Algo
//Bottom up dp
//Goal -> Relax the edges V-1 times
#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<vector<int>> edgeList;   
    public:
    void addEdge(int x,int y,int wt){
        edgeList.push_back({x, y, wt});
    }
    void bellman_ford(int src){

        //relax all edges v-1 times
        unordered_map<int,int> dist;
        set<int> nodes;

        for(auto edge : edgeList){
            dist[edge[0]] = INT_MAX;
            dist[edge[1]] = INT_MAX;
            nodes.insert(edge[0]);
            nodes.insert(edge[1]);
        }
        int V = nodes.size();
        dist[src] = 0;
        for (int i = 0; i < V - 1; i++){
            for (auto edge : edgeList)
            {
                int src = edge[0];
                int dest = edge[1];
                int wt = edge[2];

                if (dist[src] != INT_MAX and dist[src] + wt < dist[dest])
                {
                    //relax
                    dist[dest] = dist[src] + wt;
                }
            }
        }

        //detect negative wght cycle 
        for (auto edge : edgeList)
            {
                int src = edge[0];
                int dest = edge[1];
                int wt = edge[2];

                if (dist[src] != INT_MAX and dist[src] + wt < dist[dest])
                {
                    cout << "The graph contains negative weight cycle " << endl;
                    exit(0);
                }
            }

        //print all the distances
        for(auto dist_pair : dist){
            cout << "Distance of node " << dist_pair.first << " from " << src << " is " << dist_pair.second << endl;
        }
    }

};
int main(){

    Graph g;

    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, -4);
    g.addEdge(3, 1, 1);

    g.bellman_ford(1);

    return 0;
}