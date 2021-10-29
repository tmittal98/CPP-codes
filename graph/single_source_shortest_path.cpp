#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<T>> mp;
    public:
    void addEdge(T x,T y){
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    void sssp(T src){

        queue<T> q;
        unordered_map<T, int> dist;

        for(auto node : mp){
            dist[node.first] = INT_MAX;
        }

        dist[src] = 0;
        q.push(src);

        while(!q.empty()){

            T node = q.front();
            q.pop();

            list<T> nbrs = mp[node];

            for(auto nbr : nbrs){
                if(dist[nbr] == INT_MAX){
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }

        for(auto node_pair : mp){
            cout << src << " " << node_pair.first << " -> " << dist[node_pair.first]<<endl;
        }
    }
};
int main(){
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 0);
    g.addEdge(4, 5);
    g.sssp(0);
    return 0;
}

