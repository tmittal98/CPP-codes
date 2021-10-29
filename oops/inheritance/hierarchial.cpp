//Hierarchical inheritance
#include <iostream>
using namespace std;

//       -
//  ----------
//  -        -
//  -        -
//  -        -
class Shape{
    public:
        int a;
        int b;
    void get_data(int n,int m){
        a = n;
        b = m;
    }
};

class Rectangle : public Shape{
    public:
        int rectArea(){
            int res = a*b;
            return res;
        }
};

class Triangle : public Shape{
    public:
        float triArea(){
            float result = 0.5 * a * b;
            return result;
        }
};

int main() {
	 Rectangle obj1;
	 Triangle obj2;
	 
	 int len,bre,height,base;
	 
	 cout<<"Enter the length and breadth \n";
	 cin>>len>>bre;
	 
	 obj1.get_data(len,bre);
	 int areaRect = obj1.rectArea();
	 cout<<"Area of the rectangle is "<<areaRect<<endl;
	 
	 cout<<"Enter the height and base of the triangle \n";
	 cin>>height>>base;
	 
	 obj2.get_data(height,base);
	 float areaTri = obj2.triArea();
	 cout<<"Area of the triangle is : "<<areaTri<<endl;

     cout << "Press Enter\n";
     int dummyVar;
     cin >> dummyVar;
     return 0;
}