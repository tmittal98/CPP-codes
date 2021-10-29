#include <iostream>
using namespace std;

// APPROACH 1 
void partition(int arr[],int n){

    int i = 0;
    int j = 0;

    //unknown region i to n-1
    //negative region 0 to j-1
    //positive region j to i-1

    while( i <= n-1){

        if(arr[i] > 0){
            i++;
        }
        else {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
    return;
}

//APPROACH 2 TWO POINTER

// 5 -4 2 -18 9 -5 -4 1 
void moveZerosandOnes(int arr[],int n){

    int left = 0;
    int right = n - 1;

    while(left <= right){

        if(arr[left] <= 0 and arr[right] > 0){
            left++;
            right--;
        }
        else if(arr[left] > 0 and arr[right] > 0){
            right--;
        }
        else if(arr[left] <=0 and arr[right] <= 0){
            left++;
        }
        else{
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}


int main() {

    int arr[] = { 4, 3, -8, 13, -15, -11, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // cout<<"The "<<k<<"th smallest element is "<<quickSelect(arr, 0, n - 1,k-1);
    // partition(arr, n);
    moveZerosandOnes(arr, n);

    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}
