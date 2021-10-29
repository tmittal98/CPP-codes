#include<bits/stdc++.h>
using namespace std;


int main(){

    vector<int> res;
    int rowNo;
    cin >> rowNo;

    if(rowNo == 0){
        cout << "1";
        return 0;
    }
    res.push_back(1);
    res.push_back(rowNo);

    int temp = rowNo;

    for (int i = 2; i <= rowNo;i++){

        temp *= (rowNo-i+1);
        temp /= i;

        res.push_back(temp);
    }

    for(auto no : res){
        cout << no << " ";
    }
}