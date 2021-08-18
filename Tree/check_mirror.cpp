bool checkSymm(struct Node* l_root, struct Node* r_root){
    if(l_root == NULL && r_root == NULL)
        return true;
        
    if( l_root == NULL || r_root == NULL || l_root -> data != r_root -> data )
        return false;
        
    return checkSymm(l_root -> left, r_root -> right) && checkSymm(l_root -> right, r_root -> left);
}

bool isSymmetric(struct Node* root)
{
    if(root == NULL)
        return true;
    
    return checkSymm(root, root);
}