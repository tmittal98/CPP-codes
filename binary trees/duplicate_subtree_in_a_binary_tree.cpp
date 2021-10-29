
string dupSubUtil(Node* root,unordered_map<string,int> &subtrees){
    
    if(root == NULL){
        return "$";
    }
    
    if(root->left == NULL and root->right == NULL){
        return to_string(root->data);
    }
    
    string left = dupSubUtil(root->left,subtrees);
    string right = dupSubUtil(root->right,subtrees);
    string concat = left + to_string(root->data) + right;
    
    subtrees[concat]++;
    return concat;
}
bool dupSub(Node *root)
{
     unordered_map<string,int> subtrees;
     subtrees.clear();
     
     dupSubUtil(root,subtrees);
     
     for(auto s : subtrees){
         if(s.second >= 2){
             return true;
         }
     }
     
     return false;
     
}
