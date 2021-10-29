#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board,int i,int j,int no){

    //left diagonal
    int x = i;
    int y = j;

    while(x>=0 and y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }    
    //right diagonal
    x = i;
    y = j;
    while(x>=0 and y< no){
        if(board[x][y] == 1)
            return false;
        x--;
        y++;
    }
    //column
    for (int row = 0; row < i;row++){
        if(board[row][j] == 1)
            return false;
    }

    return true;
}
bool nQueen(vector<vector<int>> &board,int currRow,int no){

    //base case
    if(currRow == no){
        //If we are able to place all n queens successfully in n rows 
        //Print the board
        for (int i = 0; i < no;i++){
            for (int j = 0; j < no;j++){
                
                if(board[i][j] == 1){
                    cout << "Q ";
                }
                else{
                    cout << "_ ";
                }
            }
            cout << endl;
        }
        cout << endl
             << endl;
        return false;
    }

    //iterate on all columns and find the cell is safe or not and if safe then place the queen and ask recursion to fill
    //the rest board if recur is successfull then we return true or else we change our position and again call recursion

    for (int col = 0; col < no; col++){

        if(isSafe(board,currRow,col,no)){

            //place the queen 
            board[currRow][col] = 1;

            bool restQueensRakhPaye = nQueen(board, currRow + 1, no);
            if(restQueensRakhPaye){
                return true;
            }
            board[currRow][col] = 0;
        }
    }

    return false;
}

int main(){
    int no;
    cin >> no;

    vector<vector<int>> board(no,vector<int>(no,0));
    
    for (int i = 0; i < no;i++){
        for (int j = 0; j < no;j++){
            board[i][j] = 0;
        }
    }
   
    nQueen(board, 0, no);
   
    return 0;
}