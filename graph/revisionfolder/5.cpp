//Snakes and Ladder
#include <bits/stdc++.h>
using namespace std;

class Graph{
    map<int, list<int>> adjList;  

    public:
        void addEdge(int src,int dest){
            adjList[src].push_back(dest);
        }

        void printAdjList(){

            for(auto node_pair : adjList){
                int node = node_pair.first;
                cout << "Node " << node << " -> ";
                for(auto nbr : adjList[node]){
                    cout << nbr << "->";
                }
                cout << endl;
             }
        }

        void sssp(int src,int dest){

            queue<int> q;
            unordered_map<int, int> dist;
            unordered_map<int, int> parent;

            //buid the parent and dist hashmap
            //iterate over all the nodes in the hashmap
            for(auto node_pair : adjList){
                int node = node_pair.first;
                dist[node] = INT_MAX;
                parent[node] = node;
            }

            dist[src] = 0;
            q.push(src);

            while(!q.empty()){

                int node = q.front();
                q.pop();

                for(auto nbr : adjList[node]){
                    if(dist[nbr] == INT_MAX){
                        q.push(nbr);
                        dist[nbr] = dist[node] + 1;
                        parent[nbr] = node;
                    }
                }
            }

            //we have the dist and parent hashmap built
            //1. print the path
            int save_dest = dest;
            while(dest != src){
                cout << dest << "<-";
                dest = parent[dest];
            }
            cout << src << endl;
            //print the cost
            dest = save_dest;
            cout << "The minimum no of dice throws to reach " << dest << " from " << src << " is " << dist[dest] << endl;
        }
};
int main(){

    int board[50] = {0};

    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;
    Graph g;

    for (int i = 0; i < 36;i++){
        for (int dice = 1; dice <= 6; dice++){
            int j = i + dice;
            j += board[j];
            if(j <= 36){
                g.addEdge(i, j);
            }
        }
    }
    g.addEdge(36, 36);
    g.printAdjList();

    g.sssp(0, 36);
    
    return 0;
}