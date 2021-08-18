// Given a tree find maximum val at each level

vector<int> maximumValue(Node* root) {
    if(root == NULL)
        return {};
        
    queue<Node*> q1;
    queue<Node*> q2;
    q1.push(root);
    
    vector<int> v;
    v.push_back(root -> data);
    
    while(!q1.empty() || !q2.empty()){
        int maxm = INT_MIN;
        while(!q1.empty()){
            if(q1.front() -> left != NULL){
                q2.push(q1.front() -> left);
                maxm = max(q1.front() -> left -> data, maxm);
            }
            
            if(q1.front() -> right != NULL){
                q2.push(q1.front() -> right);
                maxm = max(q1.front() -> right -> data, maxm);
            }
                
            q1.pop();
        }
        if(maxm != INT_MIN)
            v.push_back(maxm);
        
        maxm = INT_MIN;
        while(!q2.empty()){
            if(q2.front() -> left != NULL){
                q1.push(q2.front() -> left);
                maxm = max(q2.front() -> left -> data, maxm);
            }
            
            if(q2.front() -> right != NULL){
                q1.push(q2.front() -> right);
                maxm = max(q2.front() -> right -> data, maxm);
            }
            q2.pop();
        }
        if(maxm != INT_MIN)
            v.push_back(maxm);
    }
    
    return v;
}

// better solution

void solve(Node* node,int level,vector<int> &answer)
{
    if(node==NULL)
        return ;
    if(level==answer.size())
        answer.push_back(node->data);
    else
        answer[level]=max(answer[level],node->data);
    solve(node->left,level+1,answer);
    solve(node->right,level+1,answer);
}

vector<int> maximumValue(Node* node) {
    vector<int> answer;
    solve(node,0,answer);
    return answer;
}