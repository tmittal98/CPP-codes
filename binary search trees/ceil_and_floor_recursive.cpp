// Floor and Ceil from a BST
#include  <bits/stdc++.h>
using namespace std;

class node{
  public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = this->right = NULL;
    }
};

void findCeilFloor(node* root,int val,int &ceil,int &floor){
    
    if(root){
        
        if(root->data == val){
            ceil = floor = val;
            return;
        }
        
        if(root->data < val){
            
            floor = root->data;
            findCeilFloor(root->right,val,ceil,floor);
        }
        else{
            ceil = root->data;
            findCeilFloor(root->left,val,ceil,floor);
        }
    }
    
    return;
}

int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->left->left = new node(1);
    root->right->right = new node(5);
    
    int ceil = -1, floor = -1;
    int key = -1;
    
    findCeilFloor(root,key,ceil,floor);
    
    cout<<"ceil and floor of key = "<<key<<" are "<<ceil<<" & "<<floor<<endl;
    return 0;
}
