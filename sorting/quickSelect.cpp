#include <iostream>
using namespace std;

int partition(int *arr,int p,int s,int e){

    int i , j;
    i = j = s;
    while(i <= e){
        if(arr[i] > p){
            i++;
        }
        else{
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
    return j-1;
}
int quickSelect(int *arr,int s,int e,int k){

    int pivot = arr[e];

    int pi = partition(arr, pivot, s, e);

    if(k > pi){
        return quickSelect(arr, pi + 1, e, k);
    }
    else if(k < pi){
        return quickSelect(arr, s, pi - 1, k);
    }
    else{
        return pivot;
    }
}

int main() {

    int arr[] = { 4, 3, 8, 13, 15, 11, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;

    cout<<"The "<<k<<"th smallest element is "<<quickSelect(arr, 0, n - 1,k-1);

    return 0;
}
