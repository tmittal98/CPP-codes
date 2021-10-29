#include<bits/stdc++.h>

using namespace std;

long long kadane(vector<int> v){


    //handle one special case when all elements are negative
    
    long long sum = v[0] > 0 ? v[0] : 0;

    long long max_so_far = sum;

    for (int i = 1; i < v.size(); i++){

        if(v[i] + sum < 0){
            sum = 0;
        }
        else
            sum += v[i];

        max_so_far = max(max_so_far, sum);
    }
    return max_so_far;
}
int main(){

    vector<int> v{1, 4, -2, -3, 2, 45, -9, -2, -29, 10, 12, 12, 4, -18, 10};
    cout<<kadane(v);

    return 0;
}