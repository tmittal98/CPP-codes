#include <iostream>
using namespace std;

void partition(int *arr,int n,int p){

    int i , j;
    i = j = 0;
    while(i < n){
        if(arr[i] > p){
            i++;
        }
        else{
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
    return;
}
int main() {

    int arr[] = { 4, 3, 8, 13, 15, 11, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pivot = 5;
    partition(arr,n, pivot);

    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
