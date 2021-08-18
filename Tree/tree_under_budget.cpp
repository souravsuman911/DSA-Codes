int getCount(Node *root, int k)
{
    int count = 0, level = 1;
    queue<Node *> q1;
    queue<Node *> q2;
    q1.push(root);
    
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            Node* temp = q1.front();
            q1.pop();
            
            if(temp -> left == NULL && temp -> right == NULL){
                k -= level;
                if(k >= 0)
                    count ++;
                else
                    return count;
            }
            
            if(temp -> left != NULL)
                q2.push(temp -> left);
            if(temp -> right != NULL)
                q2.push(temp -> right);
                
        }
        level ++;
        
        while(!q2.empty()){
            Node* temp = q2.front();
            q2.pop();
            
            if(temp -> left == NULL && temp -> right == NULL){
                k -= level;
                if(k >= 0)
                    count ++;
                else
                    return count;
            }
            
            if(temp -> left != NULL)
                q1.push(temp -> left);
            if(temp -> right != NULL)
                q1.push(temp -> right);
                
        }
        level ++;
    }
    
    return count;
    
}