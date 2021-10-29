#include <iostream>
using namespace std;

int merge(int *a,int s,int e){

    int mid = (s + e) / 2;

    int i = s;
    int j = mid + 1;
    int k = s;

    int temp[e - s + 1];

    int inv_count = 0;

    while(i<=mid and j<=e){

        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }
        else{
            inv_count += mid - i + 1;
            temp[k++] = a[j++];
        }
    }
    for (; i <= mid;i++){
        temp[k++] = a[i];
    }
    for (; j <= e;j++){
        temp[k++] = a[j];
    }

    return inv_count;
}

int mergeSort(int *a,int s,int e){

    if(s>=e){
        return 0;
    }

    int mid = (s + e) / 2;
    int left = mergeSort(a, s, mid);
    int right = mergeSort(a, mid+1,e);

    int across = merge(a, s, e);

    return (left + right + across);
}
int main(){
    int a[] = {4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    cout << mergeSort(a, 0, n - 1);

    return 0;
}