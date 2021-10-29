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

void printAllKSumPaths(node* root,int sum,string s,int k){
    
    if(root == NULL){
        return;
    }
    
    // cout<<"root->data "<<root->data<<"  string "<<s<<" sum " <<sum<<endl;

    string store = s;
    s+= to_string(root->data);
    sum += root->data;
    
    if(sum == k){
        cout<<"path ";
        cout<<s<<endl;
    }
    
    printAllKSumPaths(root->left,sum,s,k);
    printAllKSumPaths(root->right,sum,s,k);
    
    s = store;
    sum -= root->data;
    return;
}

void printAllKSumPathsMain(node* root,int k){
    
    if(root == NULL){
        return;
    }
    int sum = 0;
    string s("");
    
    printAllKSumPaths(root,sum,s,k);
    printAllKSumPathsMain(root->left,k);
    printAllKSumPathsMain(root->right,k);
    
    return;
}
int main() {
    node *root = new node(1);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->left->right->left = new node(1);
    root->right = new node(-1);
    root->right->left = new node(4);
    root->right->left->left = new node(1);
    root->right->left->right = new node(2);
    root->right->right = new node(5);
    root->right->right->right = new node(2);
    
    bfs(root);

    cout<<"\nK sum paths \n";
    printAllKSumPathsMain(root,5);
return 0;
}
