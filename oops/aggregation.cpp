// in cpp aggregation is a process in which one class defines another class as entity reference. It is aother way to reuse the class.
// It is a form of association that represents has-a-relationship.
//An example ::
//Employee class has the reference of address class as data member. In such a way it can reuse the menbers of address class
#include<iostream>
using namespace std;

class Address{
    public:
        string city;
        string state;
        string country;
        int pincode;
        
        Address(string city,string state,string country,int pincode){
            this->city = city;
            this->state = state;
            this->country = country;
            this->pincode = pincode;
        }
};

class Employee{
    
}


int main(){
    return 0;
}