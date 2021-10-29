#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
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


 // } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
public:
    
    void printNodesAtDistKDown(Node* root,int k,vector<int> &res){
        
        //base case
        if(root == NULL or k < 0){
            return;
        }
        
        if(k == 0){
            res.push_back(root->data);
            return;
        }
        
        printNodesAtDistKDown(root->left,k-1,res);
        printNodesAtDistKDown(root->right,k-1,res);
        
    }
    
    int printNodesAtDistK(Node* root,int target,int k,vector<int> &res){
        
        //base case
        if(root == NULL){
            //empty tree 
            return -1;
        }
        
        if(root->data == target){
            printNodesAtDistKDown(root,k,res);
            return 0;
        }
        
        int dl = printNodesAtDistK(root->left,target,k,res);
        
        if(dl != -1){
        //target is in the left sub tree
            
            if(dl +1 == k){
                res.push_back(root->data);
            }
            
            else{
                 printNodesAtDistKDown(root->right,k-dl-2,res);
            }
            
            return dl + 1;
        }
        
        int dr = printNodesAtDistK(root->right,target,k,res);
        
        if(dr != -1){
            //target node is in the right sub tree
            
            if(dr + 1 == k){
                res.push_back(root->data);
            }
            
            else{
                 printNodesAtDistKDown(root->left,k-dr-2,res);
            }
            
            return dr+1;
        }
        
        return -1;
    }
    
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int> res;
        printNodesAtDistK(root,target,k,res);
        
        sort(res.begin(),res.end());
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends