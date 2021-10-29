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
int diameter(node* root){

    if(root == NULL){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(diameter(root->left), max(diameter(root->right), lh + rh + 1));
}
class Pair{
    public:
    int diameter;
    int height;
};

Pair fastDiameter(node* root){

    
    if(root == NULL){
        Pair p;
        p.height = 0;
        p.diameter = 0;
        return p;
    }

    Pair leftPair = fastDiameter(root->left);
    Pair rightPair = fastDiameter(root->right);

    int height = max(leftPair.height, rightPair.height) + 1;
    int diameter = max(leftPair.diameter, max(rightPair.diameter, leftPair.height + rightPair.height + 1));

    Pair p;
    p.height = height;
    p.diameter = diameter;
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

    cout << "Diameter of the tree " << diameter(root) << endl;
    cout << "Diameter of the tree " << fastDiameter(root).diameter << endl;
    return 0;
}