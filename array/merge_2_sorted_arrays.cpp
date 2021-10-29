#include <bits/stdc++.h>
using namespace std;

void gapMethod(vector<int> &a,vector<int> &b){

    int n = a.size();
    int m = b.size();

    int gap = ((n+m)/2) + ((n+m)%2);
    int i, j;
    while(gap > 0){

            //compare elements in first array
            for (i = 0; i + gap < n; i++)
            {
                if (isgreater(a[i], a[i + gap]))
                    swap(a[i], a[i + gap]);
            }

            //comparing elements in both arrays
            for (j = gap > n ? gap - n : 0; i < n and j < m; i++,j++){
                if(isgreater(a[i],b[j]))
                    swap(a[i], b[j]);
            }

            if(j < m){
                //comparing elements in second array
                for (j = 0; j + gap < m; j++){
                    if(isgreater(b[j],b[j+gap]))
                        swap(b[j], b[j + gap]);
                }
            }

            if(gap <= 1){
                gap = 0;
            }
            else
                gap = ((gap/2) + (gap%2));
    }
    return;
}
void insertionSortMethod(vector<int> &a,vector<int> &b){

    int n1 = a.size();
    int n2 = b.size();

    for (int i = 0; i < n1; i++){

        if(isgreater(a[i],b[0])){
            swap(a[i], b[0]);
        }

        //correct the array 2
        for (int j = 0; j < b.size() - 1;j++){
            if(isgreater(b[j],b[j+1])){
                swap(b[j], b[j + 1]);
            }
            else
                break;
        }
    }
    
}
int main(){

    vector<int> a = {1, 5, 8, 13, 18};
    vector<int> b = {2, 3, 6, 7, 10};

    // insertionSortMethod(a, b);
    gapMethod(a, b);
    for(auto no : a )
        cout << no << " ";
    
    for(auto no : b){
        cout << no << " ";
    }
    return 0;
}