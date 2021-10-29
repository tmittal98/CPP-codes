#include<iostream>
#include<unordered_map>
#include<map>

using namespace std;
int smallestSubarray(int *a,int n,int k){

    //unordered_map<int, int> mp;
    map<int, int> mp;

    int prefixSum = a[0];
    mp[prefixSum] = 0;

    for (int i = 1; i < n;i++){
        prefixSum += a[i];
        // cout << "prefixSum " << prefixSum << " i = " << i << endl;
        mp[prefixSum] = i;
    }

    //loop through hashmap
    //check the prefix sum
    //calculate diff and find and update min_len if found
    int min_len = INT_MAX;

    // for(auto e: mp){
    //     cout << e.first << " " << e.second << endl;
    // }
    for(auto e : mp){
        int sum = e.first;
        int idx = e.second;
        
        if(sum < k){
            //there will be no subarray
            continue;
        }
        
        int diff = sum - k;
        if(diff == 0){
            // cout << "idx = " << idx << endl;
            // cout << "idx " << idx << endl;
            // cout << "sum " << sum << endl;
            min_len = min(min_len, idx);
        }
        else{
            auto itr = mp.find(diff);
            if(itr == mp.end()){
                continue;
            }
            else{
                int len = idx - itr->second;
                min_len = min(min_len, len);
            }
        }
    }

    return min_len;
}
int main(){

    int arr[] = {1, 4, 45, 6, 0, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 51;

    // int len = smallestSubarrayGivenSum(arr, n, k);
     int len = smallestSubarray(arr, n, k);
    if(len == INT_MAX){
        cout << "No such subarray";
    }
    else{
        cout << len << endl;
    }
    return 0;
}