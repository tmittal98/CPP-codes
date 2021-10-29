#include <iostream>
using namespace std;

class A{
    private:
        int a;
    public:
        A(int val){
            this->a = val;
        }
        //declaring fun as friend function of A
        friend int fun(int,int);
};

class B{
    private:
        int b;
    public:
        B(int val){
            this->b = val;
        }
    //declaring fun as frined function of B
        friend int fun(int,int);
};



int fun(int v1,int v2){
    A obj1(v1);
    B obj2(v2);
    int sum = obj1.a + obj2.b;
    cout << "The Sum is " << sum << endl;
    return sum;
}

int main(){
    fun(10,15);
    return 0;
}