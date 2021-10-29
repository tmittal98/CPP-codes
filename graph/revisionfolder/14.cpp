//Dijkstra's Algorithm
#include <bits/stdc++.h>
using namespace std;

class Custom{
    public:
    int node;
    string psf;
    int wsf;

    Custom(int n,string s,int w){
        this->node = n;
        this->psf = s;
        this->wsf = w;
    }
};

bool operator < (const Custom& obj1 ,const Custom&obj2){
    return obj1.wsf > obj2.wsf;
}

class Graph{
    map<int, list<pair<int, int>>> adjList;
    public:
        void addEdge(int src,int dest,int wght,bool bidir=true){
            adjList[src].push_back(make_pair(dest, wght));
            if(bidir){
                adjList[dest].push_back(make_pair(src, wght));
            }
        }

        void dijkstra(int src,int dest){

            unordered_map<int, bool> visited;
            for(auto node_pair : adjList){
                int node = node_pair.first;
                visited[node] = false;
            }

            priority_queue<Custom> pq;

            pq.push(Custom(src, to_string(src), 0));
        
            while(!pq.empty()){
                Custom node_data = pq.top();
                pq.pop();

                int node = node_data.node;
                string psf = node_data.psf;
                int wsf = node_data.wsf;
                
                if(visited[node]){
                    continue;
                }
                visited[node] = true;
                cout << node << " via " << psf << " @ " << wsf << endl;

                for(auto nbr : adjList[node]){
                    if(!visited[nbr.first]){
                        pq.push(Custom(nbr.first, psf + to_string(nbr.first), wsf + nbr.second));
                    }
                }
            }
        }
};
int main(){

    Graph g;

    g.addEdge(0, 1, 10);
    g.addEdge(0, 3, 40);
    g.addEdge(1, 2, 10);
    g.addEdge(2, 3, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 3);
    g.addEdge(4, 6, 8);
    g.addEdge(6, 5, 3);

    g.dijkstra(0,6);
    return 0;
}
