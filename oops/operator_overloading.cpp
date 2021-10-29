//Operator overloading 
//Overloaded + , ++ , + operators
#include <bits/stdc++.h>
using namespace std;

class Complex{
    private: 
        float real;
        float img;
        
    public:
        Complex(){}
        
        Complex(float r,float i){
            this->real = r;
            this->img = i;
        }
        void display(){
            bool isImgNeg = false;
            if(img < 0){
                cout<<real<<" "<<img<<"i"<<endl;
            }
            else{
                cout<<real<<" + "<<img<<"i"<<endl;
            }
            
        }
        //operator overoading for binary operator
        Complex operator+ (Complex obj){
            Complex c(obj.real + real,obj.img + img);
            return c;
        }
        //operator overloading for unary operator
        Complex operator-(){
            Complex temp;
            temp.real = -real;
            temp.img = -img;
            return temp;
        }
        
};

//Overloading post increment x++ and pre increment ++x operator
class Integer{
    private:
        int x;

    public:
        int getData(){
            return x;
        }
        void setData(int val){
            this->x = val;
        }
        //Pre increment operator
        Integer operator++(){
            Integer i;
            i.x = ++x;
            return i;
        }
        //Post increment operator
        Integer operator++(int){
            Integer i;
            i.x = x++;
            return i;
        }
};
int main(){
    
    Complex obj1(3,4);
    Complex obj2(4,5);
    Complex sum;
    //we can also write like this 
    sum = obj1.operator+(obj2);//here we have given the function name as + but when we use function name 
    //as operator then we have to write operator in front of that or else we can avoid writing . and operator and only write +(which is function name)
    //sum = obj1 + obj2;
    //here caller object is obj1 and argument is obj2
    //and function name is right of caller object
    cout<<"first complex no ";obj1.display();
    cout<<"second complex no ";obj2.display();
    cout<<"sum of two complex nos ";sum.display();

    //OVERLOADING UNARY OPERATOR
    //we want x = -3 functionality i.e. obj1 = -obj2 where obj1 will become -3 -4i
    obj2 = obj1.operator-();

    //we can remove operator keyword and . lets see how
    //just drop it na
    // obj2 = obj1-;
    //no this will not work becauz when we are doing it in c then we do int x = -y;
    //so we have to use the "-" operator in the similar way
    obj2 = -obj1;
    cout << "The negation of obj1 is \n";
    obj2.display();


    //Overloading of post and pre increment operator
    Integer i1, i2;
    i1.setData(5);
    i2.setData(0);
    cout << "The value of initial integer object of i1 is " << i1.getData() << endl;//5
    cout << "The value of initial integer object is i2 is " << i2.getData() << endl;//0

    //Pre increment operator i2 = ++i1;
    //we can also write like this i2 = i1.operator++();
    i2 = ++i1;
    cout << "The value of integer object after pre increment of i1 is " << i1.getData() << endl;//6
    cout << "The value of integer object after pre increment of i2 is " << i2.getData() << endl;//6

    //Post increment operator i2 = i1++;
    //we can also write like this i2 = i1.operator++(int);
    //here int is only written to differentiate btw pre and post 
    i2 = i1++;
    cout << "The value of integer object after post increment of i1 is " << i1.getData() << endl;//7
    cout << "The value of integer object after post increment of i2 is " << i2.getData() << endl;//6

    return 0;
}

//Note we cannot overload sizeof() and ?: operator