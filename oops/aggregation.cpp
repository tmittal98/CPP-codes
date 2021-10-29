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
    
    public:
        int id;
        string name;
        Address address;
        Employee(int id,string name,Address addr){
            this->id;
            this->name;
            this->address = addr;
        }

        void display(){
            cout << "The Employee ID is " << id << endl;
            cout << "The Employee Name is " << name << endl;
            cout << "The Employee Address is " << endl;
            cout << "The city name " << address.city << endl;
            cout << "The state name " << address.state << endl;
            cout << "The country name " << address.country<< endl;
            cout << "The pincode name " << address.pincode<< endl;
        }
};

int main(){
    Address addr("Kolkata", "WB", "India", 712222);
    Employee emp(129, "Tushar",addr);
    emp.display();
    return 0;
}