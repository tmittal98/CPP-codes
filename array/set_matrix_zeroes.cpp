//  Set Matrix Zeroes
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int r = matrix.size();
        int c = matrix[0].size();

        int row[r] = {0};
        int col[c] = {0};

        for (int i = 0; i < r;i++){
            for (int j = 0; j < c;j++){
                if(matrix[i][j] == 0){
                    row[i] = -1;
                    col[i] = -1;
                }
            }
        }

        for (int i = 0; i < r;i++){
            for (int j = 0; j < c;j++){
                if(row[i] == -1 or col[j] == -1){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    void setMatrix2(vector<vector<int>>& matrix){

        int col0 = 1, r = matrix.size(), c = matrix[0].size();

        for (int i = 0; i < r; i++){

            //check the zero colum element if it is 0 col0 = false mark
            col0 = matrix[i][0] == 0 ? 0 : 1;

            for (int j = 1; j < c;j++){

                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = r - 1; i >= 0; i--){
            for (int j = c - 1; j >= 1;j--){
                if(matrix[i][0] == 0 or matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }

        if(col0 == 0){
            matrix[i][0] = 0;
        }


        }
    }
};