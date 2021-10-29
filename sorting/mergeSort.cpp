#include <iostream>

using namespace std;

void merge(int *a,int s,int e){

    int m = (s + e) / 2;

    int i = s;
    int j = m + 1;
    int k = s;

    int temp[100];

    while(i<= m and j <= e){

        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }

    for (; j <= e;j++){
        temp[k++] = a[j];
    }

    for (; i <= m; i++){
        temp[k++] = a[i];
    }

    for (int k = s; k <=e;k++)
    {
        a[k] = temp[k];
    }

    return;
}
void mergeSort(int *a,int s,int e){

    if(s >= e){
        return;
    }

    int m = (s + e) / 2;

    mergeSort(a, 0, m);
    mergeSort(a, m+1, e);

    merge(a, s, e);
    return;
}
int main(){

    int a[] = { 4, 3, -1, -8, -15, -11, 3};
    int n = sizeof(a) / sizeof(a[0]);

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }

    return 0;
}