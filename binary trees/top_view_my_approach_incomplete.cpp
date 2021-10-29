// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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



class Solution
{
    map<pair<int,int>,int> mp;
    
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
      //(0,1) -> 1
      
    bool checkLineInmap(int line){
        for(auto m :mp){
            int line_no = m.first.first;
            if(line == line_no){
                return true;
            }
        }
        return false;
    }
    
    bool checkLevelInMap(int level){
        for(auto m : mp){
            if(m.first.second < level){
                return true;
            }
        }
        return false;
    }
    void topviewHelper(Node* root,int line,int level){
        
        if(root == NULL){
            return;
        }
        
        bool line_present = checkLineInmap(line);
        
        if(!line){
            mp.insert(make_pair(make_pair(line,level),root->data));
        }
        else{
            //level check
            bool level_check = checkLevelInMap(level);
            if(level_check){
                //you will not get inserted and not modify also the data
                mp.insert(make_pair(make_pair(line,level),root->data));
            }
            else{
                
            }
            
        }
        
    }
    vector<int> topView(Node *root)
    {
        int line = 0;
        int level = 1;
        topviewHelper(root,line,level);
    }

};

// Input:

    // map<int,int> 
    
    // 0,1 -> 10
    // 1,2 -> 20
    // 2,3 -> 40
    // 3,6 -> 200
    // -1 -> 30
    // -2 -> 100
    
//           0,1   
// //        10
// //     /      \
// //   20(1,2)    30
// //  /   \         \
// (2,3)40 (0,3)60      100
//     \        \ 
// (1,4)90       300 (-1,4)
//      /          \ 
// (2,5)10         800
//   /
// 200
// (3,6)
// Output: 40 20 10 30 100



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends