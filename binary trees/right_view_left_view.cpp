#include <iostream>
#include <queue>
#include <list>
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

void rightView(node* root,vector<int> &res,int &max_level,int level){

    if(root == NULL){
        return;
    }

    if(level > max_level){
        //i am visiting this level first time
        res.push_back(root->data);
        max_level++;
    }

    rightView(root->right, res, max_level, level + 1);
    rightView(root->left, res, max_level, level + 1);
    return;
}

vector<int> rightView2(node* root){

    vector<int> res;
    res.clear();

    if(root == NULL){
        return res;
    }

    list<node *> l;
    l.push_back(root);
    l.push_back(NULL);

    res.push_back(root->data);

    while (!l.empty()){

        node *f = l.front();
        l.pop_front();

        if(f == NULL){
            if(l.empty()){
                return res;
            }
            node *right = l.back();
            res.push_back(right->data);
            l.push_back(NULL);
            continue;
        }

        if (f->left){
            l.push_back(f->left);
        }
        if(f->right){
            l.push_back(f->right);
        }
    }

    return res;
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

    vector<int> res;
    static int max_level = -1;

    rightView(root, res, max_level,0);

    cout << "right view of a binary tree " << endl;
    for (auto it = res.begin(); it != res.end(); it++){
        cout << *it << " ";
    }
    //Approach 2 of right view using queue
    res.clear();
    res = rightView2(root);

    cout << endl<<"right view of a binary tree " << endl;
    for (auto it = res.begin(); it != res.end(); it++){
        cout << *it << " ";
    }
    return 0;
}