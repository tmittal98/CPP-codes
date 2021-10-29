#include <iostream>
#include <stack>
#include <string>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void printPre(node* root){

    if(root){
        cout<<root->data<<' ';

        printPre(root->left);
        printPre(root->right);
    }
    return;
}
int findIdxOfClosingBracket(string str,int s,int e){

    if(s > e){
        return -1;
    }

    stack<char> st;

    for(int i=s; i<= e; i++){

        if(str[i] == '('){
            st.push(str[i]);
        }
        else if(str[i] == ')'){
            st.pop();
        }

        if(st.empty()){
            return i;
        }
    }
    return -1;
}
node* buildTreeFromString(string str,int s,int e){

    if(s > e){
        //empty string
        return NULL;
    }
    
    node* root = new node(str[s] - '0');
    int idx = -1;

    if(s+1 <= e and str[s+1] == '(')
        //str main aur bhi masala hain kam se kam left toh hain hi
         idx = findIdxOfClosingBracket(str,s+1,e);

    if(idx != -1){
        root->left = buildTreeFromString(str,s+2,idx-1);
        root->right = buildTreeFromString(str,idx+2,e-1);
    }
    return root;
}
int main() {
    string str = "4(2(3)(1))(6(5))";
    int s=0;
    int e = str.length()-1;
    node* root = buildTreeFromString(str,s,e);
    cout<<endl;
    printPre(root);

    return 0;
}
