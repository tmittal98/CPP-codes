#include <iostream>
using namespace std;

class BaseClass{
    private :
        int a;

    public:

    BaseClass(){
        this->a = 0;
    }
    BaseClass(int val){
        this->a = val;
    }

    //making a friend function
    friend void show();
};//show() is a friend of A

class DerivedClass : public BaseClass{
    private:
        int b;

    public:

    DerivedClass(){
        this->b = 0;
    }
    DerivedClass(int val){
        this->b = val;
    }
};

void show(){

    DerivedClass obj(10);

    //trying to access the private variable of the BaseClass
    cout << "The private variable of BaseClass is " << obj.a << endl;
    
    //trying to access the private variable of the DerivedClass
    cout << "The private variable of DerviedClass is " << obj.b << endl;
}
int main(){
    show();
    return 0;
}