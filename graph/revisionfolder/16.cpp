//Kruskal's Algo
#include<bits/stdc++.h>
using namespace std;

class DSU{
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;
    public:
        DSU(set<int> node_set){
            //initialize parent and rank
            for(auto node : node_set){
                parent[node] = -1;
                rank[node] = 1;
            } 
        }

        int findSet(int node){

            if(parent[node] == -1){
                return node;
            }
            //path compression
            return parent[node] = findSet(parent[node]);
        }

        void unionSet(int node1,int node2){

            int leader1= findSet(node1);
            int leader2 = findSet(node2);

            if(leader1 != leader2){

                if(rank[leader1] < rank[leader2]){
                    parent[leader1] = leader2;
                    rank[leader2] += rank[leader1]; 
                }
                else{
                    parent[leader2] = leader1;
                    rank[leader1] += rank[leader2];
                }
            }
        }
};

class Graph{
    vector<vector<int>> edgeList;

    public:
        void addEdge(int x,int y,int w){
            edgeList.push_back({w,x,y});
        }

        int kruskal_mst(){
            set<int> node_set;

            for(auto edge : edgeList){
                node_set.insert(edge[1]);
                node_set.insert(edge[2]);
            }

            DSU disjoint_set(node_set);

            sort(edgeList.begin(),edgeList.end());

            int cost = 0;
            for(auto edge : edgeList){
                int wgt = edge[0];
                int x = edge[1];
                int y = edge[2];

                int leader1 = disjoint_set.findSet(x);
                int leader2 = disjoint_set.findSet(y);

                if(leader1 != leader2){
                    cost += wgt;
                    disjoint_set.unionSet(leader1,leader2);
                }
            }
            return cost;
        }

};

int main(){
    Graph g;

    // g.addEdge(10,1,2);
    // g.addEdge(10,1,4);
    // g.addEdge(10,4,3);
    // g.addEdge(20,4,5);
    // g.addEdge(20,1,3);
    // g.addEdge(30,2,3);
    // g.addEdge(40,2,4);
    
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
    cout<<g.kruskal_mst()<<endl;

    return 0;
}