class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        int minHD = 0, maxHD = 0;
        
        vector<int> left;
        vector<int> right;
        left.clear();
        right.clear();
        
        queue<pair<Node*,int>> q;
        
        q.push({root,0});
        
        while(!q.empty()){
            
            Node* node = q.front().first;
            int hd = q.front().second;
            
            if(hd < minHD){
                left.push_back(node->data);
                minHD = hd;
            }
            
            if(hd > maxHD){
                right.push_back(node->data);
                maxHD = hd;
            }
            
            if(node->left){
                q.push({node->left,hd-1});
            }
            if(node->right){
                q.push({node->right,hd+1});
            }
            q.pop();
        }
        
        vector<int> res;
        res.clear();
        
       reverse(left.begin(),left.end());
       
       for(auto val : left){
           res.push_back(val);
       }
       res.push_back(root->data);
       for(auto val : right){
           res.push_back(val);
       }
       
       return res;
    }
    
// Input:
//       10
//     /      \
//   20        30
//  /   \    /    \
// 40   60  90    100


// Output: 40 20 10 30 100
};