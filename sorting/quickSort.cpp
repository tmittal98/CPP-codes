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
void quickSort(int *arr,int start,int end){

    //base case
    if( start >= end){
        return;
    }

    int pivot = arr[end];
    int pivot_idx = partition(arr, pivot, start, end);

    //rec case
    quickSort(arr, start, pivot_idx - 1);
    quickSort(arr,pivot_idx + 1,end);
}

int main() {

    int arr[] = { 4, 3, 8, 13, 15, 11, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
