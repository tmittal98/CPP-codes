#include <iostream>
using namespace std;

void rightRotate(int *a,int n,int s,int e){

    int storeLast = a[e];

    for (int i = e; i > s;i--){
        a[i] = a[i - 1];
    }

    a[s] = storeLast;
    return;
}

void alternateElements(int *a,int n){

    int outOfPlace = -1;

    for (int i = 0; i < n;i++){

        if(outOfPlace >= 0){

            if((a[outOfPlace] > 0 and a[i] < 0) or (a[outOfPlace] < 0 and a[i] > 0)){

                rightRotate(a, n, outOfPlace, i);

                if(i - outOfPlace + 1 >= 1){
                    outOfPlace += 2;
                }
                else{
                    outOfPlace = -1;
                }
            }
        }

        if(outOfPlace == -1){
            //at even index we don't need 
            if((i&1 and a[i] < 0 ) || (!(i&1) and a[i] >0)){
                outOfPlace = i;
            }
        }
    }
}
int main(){

    int a[] = {2, -3, 8, 1, -1, 4, 5, 6, -7, -8};
    int n = sizeof(a) / sizeof(a[0]);

    alternateElements(a, n);

    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}