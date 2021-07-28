bool checkCompleteTree(Node *root){
    queue<Node*> q;
    q.push(root);
    bool flag = false;
    
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        
        if(temp -> left != NULL){
            if(flag == true)
                return false;
                
            q.push(temp -> left);
        }
        else
            flag = true;
            
        if(temp -> right != NULL){
            if(flag == true)
                return false;
                
            q.push(temp -> right);
        }
        else
            flag = true;
    }
    
    return true;
}

bool checkHeap(Node *root){
    if(root == NULL)
        return true;
        
    if(root -> left != NULL && root -> data < root -> left -> data)
        return false;
        
    if(root -> right != NULL && root -> data < root -> right -> data)
        return false;
    
    return checkHeap(root -> left) && checkHeap(root -> right);
}

// => main function
bool isHeap(struct Node* root){
        
        return (checkHeap(root) && checkCompleteTree(root));
}