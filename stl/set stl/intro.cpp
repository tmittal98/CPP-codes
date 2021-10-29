#include <iostream>
#include <set>
using namespace std;

int main(){

    //CREATE NORMAL SET
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(4);
    s.insert(4);

    for (set<int>::iterator it = s.begin(); it != s.end(); it++){
        cout << *it << endl;
    }
    

    //CREATE SET IN DESCENDING ORDER
    set<int, greater<int>> s1;

    s1.insert(1);
    s1.insert(1);
    s1.insert(4);
    s1.insert(5);
    s1.insert(6);
    s1.insert(8);

    for (set<int>::iterator it = s1.begin(); it != s1.end(); it++){
        cout << *it << " ";
    }

    cout << endl;

    //THIRD TYPE OF CREATING SET

    set<int> s2(s1.begin(), s1.end());

    for (set<int>::iterator it = s2.begin(); it != s2.end(); it++){
        cout << *it << " ";
    }

    cout << endl;

    //LOWER BOUND IN SET

    set<int>::iterator it = s.lower_bound(2);
    cout << "LOWER BOUND OF 2 "<<*it<<endl;
    cout << "LOWER BOUND OF 3 "<<*s.lower_bound(3)<<endl;

     //UPPER BOUND IN SET

    set<int>::iterator it1 = s.upper_bound(2);
    cout << "UPPER BOUND OF 2 "<<*it1<<endl;
    cout << "UPPER BOUND OF 3 "<<*s.upper_bound(3)<<endl;

    //CLEAR A SET

    s.clear();

    //SIZE OF A SET

    cout<<"SIZE FOF SET S1 "<<s1.size()<<endl;

    //TIME COMPLEXITY FOR SET OPERATION IS O(LOGN)
    //SET IS INTERNALLY IMPLEMENTED AS SELF BALANCED BST
    
    return 0;
}