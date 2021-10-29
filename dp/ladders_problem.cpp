#include <bits/stdc++.h>
using namespace std;


int totalWays_TD(int n,int k,int dp[]){

    //base case
    if(n == 0){
        return 1;
    }

    //Lookup
    if(dp[n] != 0){
        return dp[n];
    }

    //Calculate dp[n] for the first time
    int ans = 0;
    for (int i = 1; i <= k;i++){
        if(n-i >=0 ){
            ans += totalWays_TD(n - i, k, dp);
        }
    }

    return dp[n] = ans;
}

int totalWays_BU(int n,int k){
    
    int dp[10000] ={0};

    dp[0] = 1;
    for (int i = 1; i <= n;i++){

        int ans = 0;
        //we will go all valid k steps back
        for (int j = 1; j <= k;j++){
            if(i - j >= 0 ){
                ans += dp[i - j];
            }
        }
        dp[i] = ans;
    }
    return dp[n];
}
int main(){

    int n,k;
    cin>>n>>k;

    int dp[100000] = {0};

    cout << totalWays_TD(n, k, dp)<<endl;
    cout << totalWays_BU(n, k);
    return 0;
}