// Dijkstra’s shortest path algorithm
// C++11 introduces std::stoi (and variants for each numeric type) and std::to_string, the counterparts of the C atoi and itoa but expressed in term of std::string.

// #include <string> 

// std::string s = std::to_string(42);
// is therefore the shortest way I can think of. You can even omit naming the type, using the auto keyword:

// auto s = std::to_string(42);

#include <bits/stdc++.h>
using namespace std;

class Custom{
    public:
        int v;
        string psf;
        int wsf;
    Custom(int vertex,string psf,int wsf){
        this->v = vertex;
        this->psf = psf;
        this->wsf = wsf;
    }
};

bool operator < (const Custom &c1,const Custom &c2){
    return c1.wsf > c2.wsf;
}

class Graph{
    public:
        unordered_map<int,list<pair<int,int>>> adjList;
        
        void addEdge(int x,int y,int wt,bool bidir = true){
            adjList[x].push_back(make_pair(y,wt));
            if(bidir){
                adjList[y].push_back(make_pair(x,wt));
            }
        }
        
        void printGraph(){
            
            for(auto nodePair : adjList){
                int node = nodePair.first;
                list<pair<int,int>> nbrList = nodePair.second;
                
                cout<<node<<" -> ";
                for(auto padosi : nbrList){
                    int nbr = padosi.first;
                    int wt = padosi.second;
                    cout<<"("<<nbr<<","<<wt<<"),";
                }            
                cout<<endl;
            }
        }
        void dijktraSSSP(int src){
            
            priority_queue<Custom> pq;
            
            unordered_map<int,bool> visited;
            
            for(auto nodePair : adjList){
                int node = nodePair.first;
                visited[node] = false;
            }
            //push the (curr node,path,wgt) in priority_queue
            
            pq.push(Custom(src,to_string(src),0));
            
            while(!pq.empty()){
                
                Custom top = pq.top();
                pq.pop();
                
                if(visited[top.v]){
                    continue;
                }
                cout<<top.v<<" via "<<top.psf<<" @ "<<top.wsf<<endl;
                
                visited[top.v] = true;
                
                for(auto node_pair : adjList[top.v]){
                    int nbr = node_pair.first;
                    int wt = node_pair.second;
                    
                    //if the nbrs are unvisited then add them to priority_queue
                    if(!visited[nbr]){
                        // Custom *obj = new ;
                        pq.push(Custom(nbr,top.psf + to_string(nbr) ,top.wsf+wt));
                    }
                }
                
            }
        
        }
};

int main() {
	Graph g;
	g.addEdge(0,3,40);
	g.addEdge(0,1,10);
	g.addEdge(1,2,10);
	g.addEdge(2,3,10);
	g.addEdge(4,3,2);
	g.addEdge(4,5,3);
	g.addEdge(4,6,8);
	g.addEdge(5,6,3);
	
	g.printGraph();
	
	g.dijktraSSSP(0);
	return 0;
}