#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <climits>
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

void printTraversals(node* root){

    pair<node*,int> rt(root,1);

    stack<pair<node*,int>> s;
    s.push(rt);

    vector<int> ino;
    vector<int> pre;
    vector<int> post;
   
    while(!s.empty()){
    
        if(s.top().second == 1){
            //left,pre,level++
             pre.push_back(s.top().first->data);
            s.top().second += 1;
            if( s.top().first->left != NULL){
                s.push(make_pair(s.top().first->left,1));
            }
            
        }
        else if(s.top().second == 2){
            //right,in,level++
             ino.push_back(s.top().first->data);
            s.top().second += 1;
            if(s.top().first->right != NULL){
                s.push(make_pair(s.top().first->right,1));
            }
        }
        else{
            //level 3
            //post , s.pop()
             post.push_back(s.top().first->data);
            s.pop();
        }
    }

    cout<<"inorder "<<endl;
    for(auto e : ino){
        cout<<e<<" ";
    }
    cout<<endl;
    cout<<"preorder "<<endl;
     for(auto e : pre){
        cout<<e<<" ";
    }
    cout<<endl;
    cout<<"postorder "<<endl;
     for(auto e : post){
        cout<<e<<" ";
    }
    cout<<endl;
    return;
}

void printPre(node* root){

    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";

    printPre(root->left);
    printPre(root->right);
    return;
}

void printIn(node* root){

    if(root == NULL){
        return;
    }

    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
    return;
}

void findMaxMinHD(node* root,int &minHD,int &maxHD,int hd){
        
        if(root){
            
            if(hd < minHD){
                //update minHD
                minHD = hd;
            }
            if(hd > maxHD){
                //update maxHD
                maxHD = hd;
            }
            
            findMaxMinHD(root->left,minHD,maxHD,hd-1);
            findMaxMinHD(root->right,minHD,maxHD,hd+1);
        }
    }
    
    void printALine(node* root,int line_no,int hd,vector<int> &verticalOrder){
        
        if(root){
            
            if(line_no == hd){
                verticalOrder.push_back(root->data);
            }
            
            printALine(root->left,line_no,hd-1,verticalOrder);
            printALine(root->right,line_no,hd+1,verticalOrder);
            
        }
    }
    vector<int> verticalOrderfun(node *root)
    {
        // calc maxHD and minHD
        // for(i=minHD to maxHD){
            // printALine(line_no,hd); 
        // }
        
        int minHD = INT_MAX;
        int maxHD = INT_MIN;
        
        findMaxMinHD(root,minHD,maxHD,0);
        
        vector<int> verticalOrder;
        verticalOrder.clear();
        
        for(int i=minHD ; i <= maxHD ; i++){
            
            printALine(root,i,0,verticalOrder);
            
        }
        
        return verticalOrder;
    }
int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // printPre(root);
    // cout<<endl;
    // printIn(root);
    // cout<<endl;
    // printTraversals(root);
    vector<int> v = verticalOrderfun(root);

    for(auto x : v){
        cout<<x<<' ';
    }

    return 0;
}
        //    1
        //  /  \   
        //  2   3
        // /\   /\
        // 4 5  6 7  
