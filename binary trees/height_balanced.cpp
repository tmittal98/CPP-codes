#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* preorderBuild(){

    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    node *newRoot = new node(data);

    newRoot->left = preorderBuild();
    newRoot->right = preorderBuild();

    return newRoot;
}
void preorderPrint(node* root){

    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);

    return;
}

void inorderPrint(node* root){

    if(root == NULL){
        return;
    }
    
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);

    return;
}
void postorderPrint(node* root){

    if(root == NULL){
        return;
    }

    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";

    return;
}

int height(node* root){
    
    //base case
    if(root == NULL){
        return 0;
    }

    int leftH = height(root->left);
    int rightH = height(root->right);

    return max(leftH, rightH)+1;
}
void bfs(node* root){

    queue<node *> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node *f = q.front();
        
        if(f == NULL){
            cout << endl;
            q.pop();
            if(q.empty()){
                return;
            }
            else{
                q.push(NULL);
                continue;
            }
        }

        cout << f->data << " ";
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }

        q.pop();
    }
}
class HBPair{
    public:
        int height;
        bool isBalanced;
};

HBPair heightBalanced(node* root){

HBPair p;
    //base case
    if(root == NULL){
        p.height = 0;
        p.isBalanced = true;
        return p;
    }

    if(root->left == NULL and root->right == NULL){
        p.height = 1;
        p.isBalanced = true;
        return p;
    }

    HBPair left = heightBalanced(root->left);
    HBPair right = heightBalanced(root->right);

    int h = max(left.height, right.height) + 1;
    bool isBalanced = false;
    if(abs(left.height-right.height) <= 1 and left.isBalanced and right.isBalanced){
        isBalanced = true;
    }

    p.height = h;
    p.isBalanced = isBalanced;

    return p;
}
int main(){
    node *root = preorderBuild();

    preorderPrint(root);
    cout << endl;
    inorderPrint(root);
    cout << endl;
    postorderPrint(root);
    cout << endl;

    cout << "Height of the tree : "<<height(root) << endl;
    cout << "level order traversal" << endl;
    bfs(root);

    // cout << root->data << endl;
    // cout << root->left->data << endl;
    // cout << root->right->data << endl;
    // cout << root->left->left->data << endl;
    // cout << root->left->right->data << endl;

    HBPair p = heightBalanced(root);

    if(p.isBalanced){
        cout << "The tree is height balanced" << endl;
    }
    else{
        cout << "The tree is not height balanced" << endl;
    }
    return 0;
}