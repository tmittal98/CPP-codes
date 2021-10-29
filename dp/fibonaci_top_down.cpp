#include <bits/stdc++.h>

using namespace std;

int fib(int n,int dp[]){

    //base case
    if(n ==0 || n==1 ){
        return n;
    }

    //Lookup
    if(dp[n] != 0){
        return dp[n];
    }

    int ans = fib(n - 1,dp) + fib(n - 2,dp);
    dp[n] = ans;

    return ans;
}
int main(){

    //0 1 1 2 3 5 8 13 21 34 55 89 144
    int n;
    cin>>n;

    int dp[1000];

    for (int i = 0; i < 1000; i++)
    {
        dp[i] = 0;
    }
    cout << fib(n, dp);
    return 0;
}