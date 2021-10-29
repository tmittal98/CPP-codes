#include <bits/stdc++.h>
using namespace std;

int fib(int n){

    //base case
    if(n ==0 || n==1 ){
        return n;
    }

    int a = 0;
    int b = 1;
    int c;

    for (int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}
int main(){

    //0 1 1 2 3 5 8 13 21 34 55 89 144
    int n;
    cin>>n;

    cout << fib(n);
    return 0;
}