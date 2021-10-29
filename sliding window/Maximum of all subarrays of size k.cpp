#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<int> maxOfAllSubarraysOfSizeK(int* a,int n,int k){

    int i = 0;
    int j = 0;
    list<int> li;
    vector<int> res;

    while(j < n){
       
        while(!li.empty() and li.back() < a[j]){
            li.pop_back();
        }

        li.push_back(a[j]);

        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 == k){

            res.push_back(li.front());

            if(li.front() == a[i]){
                li.pop_front();
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


    vector<int> res = maxOfAllSubarraysOfSizeK(arr, n, k);

    for (auto it = res.begin(); it != res.end(); it++){
        cout << *it << " ";
    }
    return 0;
}