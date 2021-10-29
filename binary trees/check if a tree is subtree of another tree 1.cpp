//time complexity -> 0(n*m) n->nodes in main tree and m->nodes in small tree
// https://www.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/
#include <iostream>
#include <queue>

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

void bfs(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node* f = q.front();

        if(f == NULL){
            q.pop();
            if(q.empty()){
                break;
            }
            else{
                cout<<endl;
                q.push(NULL);
                continue;
            }
        }
        cout<<f->data<<" ";

        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
        q.pop();
    }
}
bool isEqual(node* main,node* small){
    
    if(main == NULL and small == NULL){
        return true;
    }
    
    if(main == NULL || small == NULL){
        return false;
    }
    
    return (main->data == small->data and isEqual(main->left,small->left) and isEqual(main->right,small->right));
}
bool isSubtree(node* main,node* small){
    
    //base case
    if(small == NULL){
        return true;
    }
    
    if(main == NULL){
        return false;
    }
    
    if(isEqual(main,small)){
        return true;
    }
    
    bool left = isSubtree(main->left,small);
    bool right = isSubtree(main->right,small);
    
    if(left || right){
        return true;
    }
    return false;
}
int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    
    cout<<"Tree main == \n";
    bfs(root);
    cout<<endl;
//       1
//      / \
//     2   5
//    / \
//   3   4

    node* root2 = new node(2);
    root2->left = new node(3);
    root2->right = new node(4);
    
//     2
//    / \
//   3   4
    
    cout<<"Tree small == \n";
    bfs(root2);
    cout<<endl;
    
    if(isSubtree(root,root2)){
        cout<<"the tree small is a subtree of main tree\n";
    }
    else{
        cout<<"the small tree is not a subtree of main tree\n";
    }
return 0;
}
