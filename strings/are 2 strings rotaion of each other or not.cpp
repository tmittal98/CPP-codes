#include <iostream>
using namespace std;

bool areRotattions(string s1,string s2){

    if(s1.length() != s2.length()){
        return false;
    }

    // a b a c a b a c
    // c a b a 
    s1 += s1;
    return (s1.find(s2) != string::npos);
}
int main() {

    string s1 = "abac", s2 = "caba";
    bool res = areRotattions(s1,s2);
    if(res){
        cout<<"both strings are rotations of each other";
    }
    else{
        cout<<"both strings are not rotations of each other";
    }
    return 0;
}
