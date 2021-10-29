#include <bits/stdc++.h>

using namespace std;

int fib(int n){

    if(n ==0 or n == 1){
        return 1;
    }

    int dp[10000]={0};
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
int main(){

    //0 1 1 2 3 5 8 13 21 34 55 89 144
    int n;
    cin>>n;

    cout << fib(n);
    return 0;
}