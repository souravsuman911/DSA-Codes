int height(Node *root,int &maxm){
    if(root == NULL)
        return 0;
        
    int l = height(root -> left, maxm);
    int r = height(root -> right, maxm);
    
    if(l + r > maxm)
        maxm = l + r;
        
    return 1 + max(l, r);
}


int diameter(Node* root) {
    
    int maxm = INT_MIN;
    height(root, maxm);
        
    return maxm + 1;
}