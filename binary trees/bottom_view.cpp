
void findMinHDMaxHD(Node* root,int hd,int &maxHD,int &minHD){
    
    if(root){
        
        if(hd < minHD){
            minHD = hd;
        }
        if(hd > maxHD){
            maxHD = hd;
        }
        
        findMinHDMaxHD(root->left,hd-1,maxHD,minHD);
        findMinHDMaxHD(root->right,hd+1,maxHD,minHD);
    }
    
    return;
    
}
//Function to return a list containing the bottom view of the given tree.
vector <int> bottomView(Node *root)
{
    int maxHD = 0;
    int minHD = 0;
    int hd = 0;
    
    findMinHDMaxHD(root,hd,maxHD,minHD);
    int n = abs(maxHD) + abs(minHD) + 1;
    int a[n] = {0};
    
    //current hd of root
    hd = abs(minHD);
    
    queue<pair<Node*,int>> q;
    q.push({root,hd});

    while(!q.empty()){
        
        int hd = q.front().second;
        Node* node = q.front().first;
        
        //update in array
        a[hd] = node->data;
        
        if(node->left){
            q.push({node->left,hd-1});
        }
        if(node->right){
            q.push({node->right,hd+1});
        }
        q.pop();
    }
    
    vector<int> v(a,a+n);
    return v;
}