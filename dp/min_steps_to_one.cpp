#include <bits/stdc++.h>

using namespace std;

int minStepsTD(int n,int dp[]){

    //base case
    if(n == 1){
        return 0;
    }

    //Lookup
    if(dp[n] != 0){
        return dp[n];
    }

    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    
    if(n%3 == 0){
        op1 = minStepsTD(n / 3, dp);
    }
    if(n%2 == 0){
        op2 = minStepsTD(n / 2, dp);
    }
    op3 = minStepsTD(n - 1, dp);

    int ans = min(op1, min(op2, op3)) + 1;
    dp[n] = ans;
    return ans;
}

int minStepsBU(int n){

    if(n == 1){
        return 0;
    }

    int dp[10000]= {0};

    for (int i = 2; i <= n; i++){

        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;

        if(i%3 == 0){
            op1 = dp[i / 3];
        }
        if(i%2 == 0){
            op2 = dp[i / 2];
        }
        op3 = dp[i - 1];

        dp[i] = min(op1, min(op2, op3))+1;
    }
    return dp[n];
}
int main(){

    int n;
    cin>>n;

    int dp[10000]={0};

    cout << minStepsTD(n, dp) << endl;
    cout << minStepsBU(n);

    return 0;
}