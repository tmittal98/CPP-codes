#include <bits/stdc++.h>
using namespace std;

int minCoins(int n,int coins[],int t){

    //base case
    if(n == 0){
        return 0;
    }

    int ans = INT_MAX;

    for (int i = 0; i < t;i++){
        if(n - coins[i] >= 0 ){
            int res = minCoins(n - coins[i],coins,t);
            ans = min(ans, res+1);
        }
    }

    return ans;
}

int minCoins_TD(int n,int dp[],int coins[],int t){

    //base case
    if(n == 0){
        return 0;
    }

    //Lookup
    if(dp[n] != 0){
        return dp[n];
    }

    //Calculate for first time
    int ans = INT_MAX;
    for (int i = 0; i < t;i++){
        if(n-coins[i] >=0 ){
            int res = minCoins_TD(n-coins[i],dp,coins,t);
            ans = min(ans, res + 1);
        }
    }

    dp[n] = ans;
    return dp[n];
}

int minCoins_BU(int n,int coins[],int t){

    if(n == 0){
        return 0;
    }

    int dp[10000]={0};

    for (int i = 1; i <= n; i++){

        int ans = INT_MAX;
        for (int j = 0; j < t;j++){
            if(i-coins[j] >=0){
                ans = min(ans, dp[i - coins[j]] + 1);
            }
        }
        dp[i] = ans;
    }

    return dp[n];
}
int main(){

    int n;
    cin>>n;

    int coins[] = {1, 7, 10};
    int t = sizeof(coins) / sizeof(coins[0]);

    int dp[10000] = {0};

    // cout << minCoins(n, coins, t) << endl;
    cout << minCoins_TD(n,dp, coins, t)<<endl;
    cout << minCoins_BU(n, coins, t);
    return 0;
}