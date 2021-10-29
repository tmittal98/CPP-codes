#include <bits/stdc++.h>
using namespace std;

bool ratInAMaze(vector<vector<int>> board,vector<vector<int>> &path,int i,int j,int m,int n){

    //Base case
    if(i == m and j == n){

        path[i][j] = 1;
        //Print the path

        for (int row = 0; row <= m; row++){
            for (int col = 0; col <= n; col++){
                cout << path[row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
        //backtrack
        path[i][j] = 0;
        return true;
    }

    //Check if we are inside board
    if(i > m || j > n){
        return false;
    }
    //check if there is no blockage at curr cell
    if(board[i][j] == -1){
        return false;
    }

    //assume path exists from here 
    path[i][j] = 1;

    //explore right
    bool rightSuccess = ratInAMaze(board, path, i, j + 1, m, n);
    //explore down
    bool downSuccess = ratInAMaze(board, path, i + 1, j, m, n);

    //backtrack as we travelled both ways right + down
    path[i][j] = 0;

    if(rightSuccess || downSuccess){
        return true;
    }
    return false;
}

int main(){

    int m = 4, n = 4;

    // 0 0 0 0
    // 0 0 X 0
    // 0 0 X 0
    // 0 0 0 0

    vector<vector<int>> board = {
        {0, 0, 0, 0},
        {0, 0, -1, 0},
        {0, 0, -1, 0},
        {0, 0, 0, 0}};

    vector<vector<int>> path(4, vector<int>(4, 0));

    bool res = ratInAMaze(board, path, 0, 0, m - 1, n - 1);

    if(!res){
        cout << "Path does not exists" << endl;
    }

    return 0;
}