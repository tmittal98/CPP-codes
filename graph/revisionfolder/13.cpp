//FLOOD FILL ALGO 
//GRAPH COLORING
#include <bits/stdc++.h>

using namespace std;


//     n
// w       e
//     s

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};


void floodfill(char mat[][30],int i,int j,int r,int c,char ch,char color){

    //we must be inside the matrix
    if(i<0 or j<0 or i>r or j>c){
        return;
    }

    if(mat[i][j] != ch){
        return;
    }
    
    //color
    mat[i][j] = color;

    for (int k = 0; k < 4;k++){
        floodfill(mat, i + dx[k], j + dy[k], r, c, ch, color);
    }
    return;
}
void print(char mat[][30],int r,int c){

    for (int i = 0; i < r;i++){
        for (int j = 0; j < c;j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
}
int main(){
    int r, c;
    cin >> r >> c;

    char mat[r][30];

    for (int i = 0; i < r;i++){
        for (int j = 0; j < c;j++){
            cin >> mat[i][j];
        }
    }

    print(mat,r,c);
    floodfill(mat, 6, 15, r - 1, c - 1, '.', 'r');
    print(mat,r,c);
    return 0;
}