#include<iostream>
#include<vector>
#include<list>
using namespace std;

void printFirstNegativeInteger(int *arr,int k,int n){

    for (int i = 0; i <= n - k;i++){
        int negEle = INT_MAX;

        for (int j = i; j <= i + k - 1;j++){
            if(arr[j] <  0){
                
                if(negEle == INT_MAX){
                    negEle = arr[j];
                    break;
                }
            }
        }
       if(negEle == INT_MAX){
           cout << 0 << " ";
       }
       else{
           cout << negEle << " ";
       }
    }
    cout<<endl;
    return;
}

vector<int> slidingWindow(int *a,int n,int k){

    int i = 0, j = 0;
    list<int> negativeNums;
    vector<int> res;

    while(j < n){
        
        if(a[j] < 0){
            negativeNums.push_back(a[j]);
        }

        // cout << " j = " << j << " ";
        // for(auto e : negativeNums){
        //     cout << e << " ";
        // }
        // cout << endl;
        
        if(j-i+1 < k){
            j++;
            continue;
        }

        if(j-i+1 == k){

            if(negativeNums.size() != 0){
                res.push_back(negativeNums.front());
            }
            else{
                res.push_back(0);
            }

            if(negativeNums.front() == a[i]){
                negativeNums.pop_front();
            }
            i++;
            j++;
        }
    }

    return res;
}
int main()
{
    int arr[] = { 12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printFirstNegativeInteger(arr, k, n);

    vector<int> res = slidingWindow(arr, n, k);

    for (auto it = res.begin(); it != res.end(); it++){
        cout << *it << " ";
    }
    return 0;
}