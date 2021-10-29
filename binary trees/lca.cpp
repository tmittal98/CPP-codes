#include<bits/stdc++.h>
using namespace std;
// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Custom{
    public:
        bool hasKeyP;
        bool hasKeyQ;
        Node* node;
};

Custom* lcaHelper(Node* root,int p,int q){
    
    //base case
    if(root == NULL){
        return NULL;
    }
    
    Custom* left = lcaHelper(root->left,p,q);
    Custom* right = lcaHelper(root->right,p,q);
    
    if(left != NULL and left->node !=NULL){
        return left;
    }
    
    if(right != NULL and right->node != NULL){
        return right;
    }
    
    if(left!= NULL and right != NULL){
        Custom* c = new Custom();
        c->hasKeyP = true;
        c->hasKeyQ = true;
        c->node = root;
        return c;
    }
    
    Custom* c = new Custom();
    
    if(root->data == p){
        
        c->hasKeyP = true;
        
        c->hasKeyQ = (left?left->hasKeyQ:false )or (right?right->hasKeyQ:false);
        
        if(c->hasKeyP == true and c->hasKeyQ == true){
            c->node = root;
            return c;
        }
        else{
            c->node = NULL;
            return c;
        }
    }
    
    if(root->data == q){
        
        c->hasKeyQ = true;
        
        c->hasKeyP = (left?left->hasKeyP:false ) or (right?right->hasKeyP:false);
        
        if(c->hasKeyP == true and c->hasKeyQ == true){
            c->node = root;
            return c;
        }
        else{
            c->node = NULL;
            return c;
        }
    }
    
    if(left != NULL){
        return left;
    }
    
    if(right != NULL){
        return right;
    }
    
    return NULL;
}
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2)
    {
     Custom* c = lcaHelper(root,n1,n2);
     
     if(c == NULL){
         return NULL;
     }
     
     return c->node;
    }
};

// { Driver Code Starts.

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;
    }
    return 0;
}
  // } Driver Code Ends