//Floyd Warshall Algo
//DP based Algo 
#include <bits/stdc++.h>
#define inf 1000000
using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int>> graph){

    vector<vector<int>> dist(graph);

    int N = dist.size();
    //N phases run
    for (int p = 0; p < N; p++){

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                dist[i][j] = min(dist[i][j], dist[i][p] + dist[p][j]);
            }
        }
    }

    return dist;
}
int main(){
    vector<vector<int>> graph = {
            {0, inf, -2, inf},
            {4, 0, 3, inf},
            {inf, inf, 0, 2},
            {inf, -1, inf, 0}
        };

    vector<vector<int>> resultant_mat = floyd_warshall(graph);

    for (int i = 0; i < resultant_mat.size(); i++){
        for (int j = 0; j < resultant_mat.size(); j++){
            cout << resultant_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}