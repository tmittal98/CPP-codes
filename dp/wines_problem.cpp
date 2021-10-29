#include <bits/stdc++.h>
using namespace std;

int maxProfit(int prices[],int i,int j,int y){

    //base case
    if(i>j){
        return 0;
    }

    int op1 = prices[i] * y + maxProfit(prices, i + 1, j, y + 1);
    int op2 = prices[j] * y + maxProfit(prices, i, j - 1, y + 1);

    return max(op1, op2);
}

int maxProfit_TD(int prices[],int i,int j,int y,int dp[][100]){

    //base case
    if(i>j){
        return 0;
    }

    //Lookup
    if(dp[i][j] != 0){
        return dp[i][j];
    }

    //First Time Calcuate
    int op1 = prices[i] * y + maxProfit_TD(prices, i + 1, j,y, dp);
    int op2 = prices[j] * y + maxProfit_TD(prices, i, j - 1,y, dp);

    dp[i][j] = max(op1, op2);

    return dp[i][j];
}

int main(){

    int winePrices[] = {2, 3, 5, 1,4};

    int dp[100][100];
    for (int i = 0; i < 100;i++){
        for (int j = 0; j < 100;j++){
            dp[i][j] = 0;
        }
    }

    cout << maxProfit(winePrices, 0, 4, 1)<<endl;
    cout << maxProfit_TD(winePrices, 0, 4, 1,dp);

    return 0;
}