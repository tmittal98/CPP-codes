#include <iostream>
using namespace std;

int unionfun(int *a,int *b,int n,int m){

    int unionArray[n + m] = {INT_MIN};
    int i = 0;
    int j = 0;

    int k = 0;

    while(i< n and j < m){

        if(unionArray[0] == INT_MIN){
            //no element is there we can insert the element
            if(a[i] < b[j]){
                unionArray[k++] = a[i++];
            }
            else if(a[i] > b[j]){
                unionArray[k++] = b[j++];
            }
            else{
                unionArray[k++] = b[j++];
                i++;
            }
            continue;
        }

        if(a[i] < b[j]){
            if(unionArray[k-1] == a[i]){
                //a[i] is already present here
                i++;
            }
            else{
                unionArray[k++] = a[i++];
            }
        }
        else if(a[i] > b[j]){
            if(unionArray[k-1] == b[j]){
                j++;
            }
            else{
                unionArray[k++] = b[j++];
            }
        }
        else{
            i++;
            if(unionArray[k-1] == b[j]){
                j++;
            }
            else{
                unionArray[k++] = b[j++];
            }
        }
    }

    while(i<n){
        
        if(unionArray[k-1] == a[i]){
            //a[i] is already present here
            i++;
        }
        else{
            unionArray[k++] = a[i++];
        }
    }

    while(j<m){
        if(unionArray[k-1] == b[j]){
            j++;
        }
        else{
            unionArray[k++] = b[j++];
        }
    }

    for (int i = 0; i < k;i++){
        cout << unionArray[i] << " ";
    }
    cout << endl;
    return k ;
}

int intersection(int *a,int  *b,int n,int m){

    int size = n > m ? n : m;
    int intersect[size] = {INT_MIN};

    int i = 0;
    int j = 0;
    int k = 0;

    /*
        1 1 1 2 2 2 3 4 5 6
        1 1 1 3 4 5 
    */
    while(i<n and j<m){

        if(a[i] == b[j]){
            //now a[i] || b[j] should not be present in intersect
            if(k == 0){
                intersect[k++] = a[i++];
                j++;
                continue;
            }
            else{
                if(intersect[k-1] != a[i]){
                    intersect[k++] = a[i++];
                    j++;
                    continue;
                }
                else{
                    i++;
                    j++;
                }
            }
        }
        else if(a[i] < b[j]){
            i++;
        }
        else 
        {
            //b[j] < a[i]
            j++;
        }
    }

    for (int i = 0; i < k;i++){
        cout << intersect[i] << " ";
    }
    cout << endl;

    return k;
}
int main(){

    int a[] = {1, 3, 5, 6, 8, 9};
    int b[] = {1, 1,1, 4, 5};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    // cout<<unionfun(a, b, n, m);
    cout<<intersection(a, b, n, m);

    return 0;
}