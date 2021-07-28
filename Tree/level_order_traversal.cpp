vector<int> levelOrder(Node* root)
{
    queue<Node *> q;
    vector<int> v;
    q.push(root);
    
    while(!q.empty()){
        v.push_back(q.front() -> data);
        
        if(q.front() -> left != NULL)
            q.push(q.front() -> left);
        
        if(q.front() -> right != NULL)
            q.push(q.front() -> right);
            
        q.pop();
    }
    
    return v;
    
}