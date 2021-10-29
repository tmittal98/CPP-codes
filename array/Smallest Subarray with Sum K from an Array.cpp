#include <iostream>
#include<map>
using namespace std;

int smallestSubarrayGivenSum(int *a,int n,int k){

    //if one element is greater than or equal to k then return size 1
    for (int i = 0; i < n;i++){
        if(a[i] == k){
            return 1;
        }
    }

    //{2, 4, 6, 10, 2, 1}, K = 12 
    
    //2 4 6  -> 3
    //10 2 -> 2
    int min_len = INT_MAX;

    for (int start = 0; start < n;start++){
        int sum = 0;
        for (int end = start; end < n; end++){
            sum += a[end];
            if(sum  == k){
                int len = end - start + 1;
                min_len = min(min_len, len);
                break;
            }
        }
    }

    return min_len;
}
int smallestSubarray(int *a,int n,int k){

    map<int, int> mp;

    int prefixSum = a[0];
    mp[prefixSum] = 0;

    for (int i = 1; i < n;i++){
        prefixSum += a[i];
        mp[prefixSum] = i;
    }

    //loop through hashmap
    //check the prefix sum
    //calculate diff and find and update min_len if found
    int min_len = INT_MAX;

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
            min_len = min(min_len, idx + 1);
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

    int arr[] = { 1, 2, 4, 3, 2, 4, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 7;

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