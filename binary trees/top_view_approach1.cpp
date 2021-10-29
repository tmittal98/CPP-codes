class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    
    vector<int> topView(Node *root)
    {
        //queue<Node* ,int>
        //map<int,int> 
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        map<int,int> mp;
        
        while(!q.empty()){ //o(n)
                
            Node* node = q.front().first;
            int hd = q.front().second;
            
            if(mp.find(hd) == mp.end()) //o(logn)
                mp[hd] = node->data;
            
           if(node->left){
               q.push({node->left,hd-1});
           }
           if(node->right){
               q.push({node->right,hd+1});
           }
           q.pop();
        }
        
        vector<int> v;
        
        for(auto m: mp){
            v.push_back(m.second);
        }
        
        return v;
        
    }
    
    // time complexity = O(nlogn)
    // space compleity = queue -> O(n) map -> o(n) overall = o(n)

};