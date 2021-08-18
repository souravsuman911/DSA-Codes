vector<int> inOrder(Node* root)
{
    stack<Node*> st;
    vector<int> ans;
    Node *curr = root;
    
    while(!st.empty() || curr != NULL){
        
        while(curr != NULL){
            st.push(curr);
            curr = curr -> left;
        }
        
        ans.push_back(st.top() -> data);
        curr = st.top() -> right;
        st.pop();
    }
    
    return ans;
}