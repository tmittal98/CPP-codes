#include <iostream>
#include <map>

using namespace std;


int main(){

    map<int, int> mp;

    for (int i = 1; i <= 10;i++){
        mp[100] = i;
    }

    cout << mp[100] << endl;
    return 0;
}