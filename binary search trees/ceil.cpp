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

int ceil(node* root,int val){
    
    if(root == NULL){
        return -1;
    }
    
    if(root->data == val){
        return root->data;
    }
    
    else if(root->data < val){
        return ceil(root->right,val);
    }
    
    int ceil_val = ceil(root->left,val);
    
    return ceil_val >= val ? ceil_val : root->data;
}
int main() {
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->left->left = new node(1);
    root->right->right = new node(5);
 
    cout<<ceil(root,6);
    return 0;
}
