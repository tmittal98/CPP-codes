class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    void topViewHelper(Node* root,int hd,int vd,map<int,pair<int,int>> &mp){
        
        if(root){
            
            if(mp.find(hd) == mp.end()){
                mp[hd] = {vd,root->data};
            }
            else if(mp[hd].first > vd){
                mp[hd] = {vd,root->data};
            }
            
            topViewHelper(root->left,hd-1,vd+1,mp);
            topViewHelper(root->right,hd+1,vd+1,mp);
        }
        return;
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int,pair<int,int>> mp;
        mp.clear();
        
        //map<hd,<vd,val>>;
        int hd = 0, vd = 0;
        topViewHelper(root,hd,vd,mp);
        
        vector<int> res;
        res.clear();
        
        for(auto m : mp){
            res.push_back(m.second.second);    
        }
        return res;
    }
    
    // time complexity -> o(nlogn) preorder + map 
    // space complexity -> o(n) map 
    // auxilary space -> o(h)  
};