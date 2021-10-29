#include <iostream>
#include <math.h>

using namespace std;

void insertionSort(int *a,int n){

    for (int i = 1; i < n;i++){

        for (int j = i - 1; j >= 0;j--){
            if(isgreater(a[j],a[j+1])){
                swap(a[j], a[j + 1]);
            }
            else{
                break;
            }
        }
    }

    return;
}

int main(){
    int arr[] = {2, 3, 5, 1, 6, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}