// flood fill algorithm
#include <iostream>
using namespace std;

//NESW
//             N
//             (i-1,j)
//              | 
// W(i,j-1)----- ----(i,j+1)E
//              |
//              (i+1,j)
//              S
             
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
const int r=15,c=30;

void print(char mat[r][c]){
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }
cout<<endl;
}
void floodfill(char mat[r][c],int i,int j,char ch,char color){
    
    //check if current cell is within the matrix
    if(i<0 or j<0 or i>=15 or j>=30){
        return;
    }
    
    //figure boundary
    if(mat[i][j] != ch){
        return;
    }
    mat[i][j] = color;
    //print(mat);
    for(int k=0;k<4;k++){
        floodfill(mat,i+dx[k],j+dy[k],ch,color);
    }
	return;
}
int main() {
	
	//cin>>r>>c;
	
	char input[15][30];
	
	for(int i=0;i<r;i++){
	    for(int j=0;j<c;j++){
	        cin>>input[i][j];
	    }
	}
	
	print(input);
	floodfill(input,8,13,'.','r');
	print(input);
	
	return 0;
}