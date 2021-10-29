#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main() {
    list<char> l1;
    list<char> l2;

    //abcd
    l1.push_back('a');
    l1.push_back('b');
    l1.push_back('c');
    l1.push_back('d');
    // l1.push_back('a');

    l2.push_front('a');
    l2.push_front('b');
    l2.push_front('c');
    l2.push_front('d');
    // l2.push_front('a');
    
    
    for(char ch : l1){
        cout<<ch<<"->";
    }
    cout<<endl;

    //l2.sort();
    //l2.reverse();

    for(char ch : l2){
        cout<<ch<<"->";
    }
    cout<<endl;

    if(l1 == l2){
        cout<<"palindrome";
    }
    else{
        cout<<"not palindrome";
    }
    cout<<endl;

    for(list<char>::iterator it = l1.begin() ; it != l1.end(); it++){
        cout<<*it<<"-->";
    }
    cout<<endl;

    l1.remove('a');
    cout<<"after removal of a from list 1"<<endl;

    for(list<char>::iterator it = l1.begin() ; it != l1.end(); it++){
        cout<<*it<<"-->";
    }
    cout<<endl;

    list<char>::iterator it = l2.begin();

    cout<<"after removal of first character from l2 "<<endl;
    l2.erase(it);

     for(list<char>::iterator it = l2.begin() ; it != l2.end(); it++){
        cout<<*it<<"-->";
    }
    cout<<endl;

   it = l2.begin();

   cout<<"after inserting d character in l2 list at begining "<<endl;
   
   l2.insert(it,'d');
   for(list<char>::iterator it = l2.begin() ; it != l2.end(); it++){
        cout<<*it<<"-->";
    }
    cout<<endl;

    return 0;
}
