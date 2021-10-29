//Operator overloading 
#include <bits/stdc++.h>
using namespace std;

class Complex{
    private: 
        float real;
        float img;
        
    public:
        //methods
        Complex(){}
        
        Complex(float r,float i){
            this->real = r;
            this->img = i;
        }
        void display(){
            cout<<real<<" + "<<img<<"i"<<endl;
        }
        
        Complex operator+ (Complex obj){
            
            Complex c(obj.real + real,obj.img + img);
            return c;
        }
        
};
int main(){
    
    Complex obj1(3,4);
    Complex obj2(4,5);
    Complex sum;
    sum = obj1 + obj2;
    cout<<"first complex no ";obj1.display();
    cout<<"second complex no ";obj2.display();
    cout<<"sum of two complex nos ";sum.display();
    
    return 0;
}