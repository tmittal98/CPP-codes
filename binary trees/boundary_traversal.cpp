//check for this input this is a good input 
// 4 10 N 5 5 N 6 7 N 8 8 N 8 11 N 3 4 N 1 3 N 8 6 N 11 11 N 5 8
class Solution {
public:
    void calcLeft(Node* root,vector<int> &left){
                
        if(root){
            left.push_back(root->data);
            if(root->left)
                calcLeft(root->left,left);
            else
                calcLeft(root->right,left);
        }
        return;
    }
    void calcRight(Node* root,vector<int> &right){
                
        if(root){
            right.push_back(root->data);
            if(root->right)
                calcRight(root->right,right);
            else
                calcRight(root->left,right);
        }
        return;
    }
    void calcMid(Node* root,vector<int> &mid){
        
        if(root == NULL)
            return;
            
        if(root->left == NULL and root->right == NULL){
            mid.push_back(root->data);
            return;
        }
        calcMid(root->left,mid);
        calcMid(root->right,mid);
        return;
    }
    vector <int> printBoundary(Node *root)
    {
        if(root == NULL){
            vector<int> v;
            v.clear();
            return v;
        }
        if(root->left == NULL and root->right == NULL){
            vector<int> v;
            v.push_back(root->data);
            return v;
        }
        
        vector<int> left,right,mid;
        left.clear();
        right.clear();
        mid.clear();
        
        calcLeft(root->left,left);
        calcMid(root,mid);
        calcRight(root->right,right);
        
        
        if(right.size() > 0)
            mid.pop_back();
        
        reverse(right.begin(),right.end());
        
        vector<int> final;
        final.clear();
        
        final.push_back(root->data);//adding root to the res vector
        
        for(auto node : left){
            final.push_back(node);
        }
        
        int i=0;
        if(left.size() > 0){
            i = 1;
        }
        for(;i < mid.size() ; i++){
            final.push_back(mid[i]);
        }
        for(auto node : right){
            final.push_back(node);
        }
        
        return final;
    }
};
