class Custom{
    public:
    int max;
    int min;
    int size;
    bool isBranchOkay;
};


Custom largestBSTHelper(Node* root,int &global_max){
    
    Custom p;
    if(root == NULL){
        p.max = INT_MIN;
        p.min = INT_MAX;
        p.size = 0;
        p.isBranchOkay = true;
        return p;
    }
    
    if(root->left == NULL and root->right == NULL){
        p.max = p.min = root->data;
        p.size = 1;
        p.isBranchOkay = true;
        return p;
    }
    
    Custom left = largestBSTHelper(root->left,global_max);
    Custom right = largestBSTHelper(root->right,global_max);
    
    
    //check if a bst is possible or not
    if(left.isBranchOkay and right.isBranchOkay and (left.max < root->data) and (right.min > root->data)){
        // cout<<"root->data "<<root->data<<endl;
        global_max = max(global_max,left.size + right.size + 1);
    }
    
    p.max = max(left.max,max(right.max,root->data));
    p.min = min(left.min,min(right.min,root->data));
    p.size = left.size + right.size + 1;
    
   
    if(!(left.isBranchOkay and right.isBranchOkay and (left.max < root->data) and (right.min > root->data))){
        p.isBranchOkay = false;
    }
    else{
        p.isBranchOkay = true;
    }        
    // if(root->data == 7){
    //     cout<<"left.max "<<left.max<<endl;
    //     cout<<"right.min "<<right.min<<endl;
    //     cout<<"size = "<<p.size<<endl;
    //     cout<<"min = "<<p.min<<endl;
    //     cout<<"max = "<<p.max<<endl;
    //     cout<<"isBranchOkay "<<p.isBranchOkay<<endl;
    // }
    return p;
}

int largestBst(Node *root)
{
	int global_max = 1;
    largestBSTHelper(root,global_max);
    return global_max;
}