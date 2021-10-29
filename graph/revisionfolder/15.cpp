//DSU Logic to detect cycle in a undirected graph
//Optimizations on DSU
//1. Path Compression
//2. Union By Rank
#include<bits/stdc++.h>
using namespace std;

class Graph{
    list<pair<int, int>> edgeList;
    set<int> node_set;

public:
    void addEdge(int x,int y){
        edgeList.push_back(make_pair(x, y));
        node_set.insert(x);
        node_set.insert(y);
    }

    int findSet(int node,unordered_map<int,int> &parent){
        
        if(parent[node] == -1){
            return node;
        }
        return parent[node] = findSet(parent[node],parent);
    }
    void unionSet(int node1,int node2,unordered_map<int,int> &parent,unordered_map<int,int> &rank){

        int s1 = findSet(node1,parent);
        int s2 = findSet(node2,parent);

        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

    bool contains_cycle(){

        //DSU logic apply
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;

        for(auto node : node_set){
            parent[node] = -1;
            rank[node] = 1;
        }

        //iterate over the edgeList
        for(auto edge : edgeList){
            int x = edge.first;
            int y = edge.second;

            int s1 = findSet(x, parent);
            int s2 = findSet(y, parent);

            if(s1 != s2){
                unionSet(s1, s2, parent, rank);
            }
            else
                return true;
        }
        return false;
    }


};
int main(){

    Graph g;

    // g.addEdge(0, 1);
    // g.addEdge(0, 3);
    // g.addEdge(1, 2);
    // g.addEdge(3, 4);
    // g.addEdge(4, 5);
    // g.addEdge(3, 2);
    g.addEdge(0, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    if(g.contains_cycle()){
        cout << "The graph contains cycle" << endl;
    }
    else{
        cout << "The graph does'nt contains cycle" << endl;
    }
    return 0;
}