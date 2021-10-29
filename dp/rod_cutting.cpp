#include <bits/stdc++.h>
using namespace std;


int maxProfit_TD(int len,int prices[],int dp[]){

    //base case
    if(len <= 0){
        return 0;
    }
    //Lookup
    if(dp[len] != 0){
        return dp[len];
    }

    //First Time calculate
    int maxProfit = INT_MIN;
    for (int i = 0; i < len;i++){
        int cut = i + 1;
        int profit = prices[i] + maxProfit_TD(len - cut, prices, dp);
        maxProfit = max(maxProfit, profit);
    }

    dp[len] = maxProfit;
    return maxProfit;
}

int maxProfit_BU(int len,int prices[]){

    int dp[10000] = {0};

    for (int i = 1; i <= len; i++){

        int maxProfit = INT_MIN;
        for (int j = 0; j < i; j++){
            int cut = j + 1;
            int profit = prices[j] + dp[i - cut];
            maxProfit = max(maxProfit, profit);
        }
        dp[i] = maxProfit;
    }

    return dp[len];
}
int main(){

    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int prices2[] = {3, 5, 8, 9, 10, 17, 17, 20};

    int len = sizeof(prices) / sizeof(prices[0]);
    
    int dp[100000] = {0};

    cout<<maxProfit_TD(len, prices2, dp)<<endl;
    cout<<maxProfit_BU(len, prices2);

    return 0;
}