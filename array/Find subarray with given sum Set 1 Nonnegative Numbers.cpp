#include <iostream>
using namespace std;
/*
int subarraysWithTargetSum(int a[],int n,int k){

    int left = 0;
    int right = 0;

    int sum = a[0];
    int count = 0;

    for (int i = 1; i < n;i++){

        while(sum > k){
            sum -= a[left];
            left++;
        }

        if(sum == k){
            for (int j = left; j <= right;j++){
                cout << a[j] << " ";
            }
            cout << endl;
            count++;
            right++;
            sum += a[right];
            continue;
        }

        if(sum < k){
            right++;
            sum += a[right];
        }
    }
}
*/
//gfg code
int subArraySum(int a[],int n,int k){

    int sum = a[0];
    int start = 0;
    int i;

    for (i = 1; i <= n;i++){

        while(sum > k and start < i-1){
            sum -= a[start];
            start++;
        }

        if(sum == k){
            cout << "sum found between indexes " << start << " and " << i - 1;
            return 1;
        }

        if(i<n){
            sum += a[i];
        }
    }

    cout << "No such subarray ";
    return 0;
}
int main(){
    int a[] = {1, 4, 20, 3, 10, 5, 33};
    int n = sizeof(a) / sizeof(a[0]);
    int target = 33;

    subArraySum(a, n, target);

    return 0;
}