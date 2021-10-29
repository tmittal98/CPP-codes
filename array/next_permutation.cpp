#include <bits/stdc++.h>
using namespace std;

vector<int> my_next_permutation(vector<int> &perm){

    int idx = perm.size() - 1;
    while(idx > 0){
        if(perm[idx-1] < perm[idx]){
            break;
        }
        idx--;
    }
    if(idx == 0){
        sort(perm.begin(), perm.end());
        return perm;
    }
    int smallIdx = idx - 1;
    int maxIdx = perm.size() - 1;
    int maxE = INT_MIN;
    for (int i = perm.size() - 1; i > smallIdx; i--){
        if(perm[i] > maxE){
            maxIdx = i;
            maxE = perm[i];
            break;
        }
    }
    swap(perm[smallIdx], perm[maxIdx]);
    sort(perm.begin() + smallIdx + 1, perm.end());
    return perm;
}
int main(){

    vector<int> v {7,6,3,5,2,4,1};
    v = my_next_permutation(v);
    for(auto no : v){
        cout << no << " ";
    }
    return 0;
}
