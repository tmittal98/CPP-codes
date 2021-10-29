#include <iostream>
using namespace std;

//Approach 1
void shift(int arr[],int n){

    int i = 0;
    int j = 0;

    while(i<= n-1){

        if(arr[i] > 0){
            i++;
        }

        else{

            int negativeNum = arr[i];

            for (int k = i; k >= j +1;k--){
                arr[k] = arr[k - 1];
            }
            arr[j] = negativeNum;
            j++;
            i++;
        }

    }
}

//Approach 2
void mergeOptimised(int *a,int s,int e){

    int m = (s + e) / 2;

    int n1 = m - s + 1;
    int n2 = e - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1;i++){
        L[i] = a[i + s];
    }

    for (int i = 0; i < n2;i++){
        R[i] = a[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = s;

    //copy negative elements from left array
    while(i <= n1-1 and L[i] <= 0){
        a[k++] = L[i++];
    }

    //copy negative elements from right array
    while(j <= n2-1 and R[j] <= 0){
        a[k++] = R[j++];
    }

    //copy positive from left
    while(i<=n1-1){
        a[k++] = L[i++];
    }

    //copy positive from right
    while(j<=n2-1){
        a[k++] = R[j++];
    }

    return;
}
//Approach 3
void reverse(int *a,int s,int e){

    while(s <= e){
        swap(a[s], a[e]);
        s++;
        e--;
    }
    return;
}
void mergeOptimised2(int *a,int s,int e){

    int m = (s + e) / 2;

    int i = s;
    int j = m + 1;

    // ln lp rn rp  

    while(i<=m and a[i] < 0){
        i++;
    }

    while(j<=e and a[j] < 0){
        j++;
    }

    reverse(a, i, m);
    reverse(a, m+1, j-1);
    reverse(a, i, j-1);

    return;
}

void mergeSort(int *a,int s,int e){

    if(s >= e){
        return;
    }

    int m = (s + e) / 2;

    mergeSort(a, 0, m);
    mergeSort(a, m+1, e);

    // mergeOptimised(a, s, e);
    mergeOptimised2(a, s, e);
    return;
}

int main() {

    int arr[] = { 4, 3, -1, -8, -15, -11, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // shift(arr, n);//TC O(N^2)

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
