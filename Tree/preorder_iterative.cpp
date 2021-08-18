vector<int> preOrder(Node* root)
{
    stack<Node*> st;
    vector<int> ans;
    Node *curr = root;
    
    while(!st.empty() || curr != NULL){
        
        while(curr != NULL){
            st.push(curr);
            ans.push_back(st.top() -> data);
            curr = curr -> left;
        }
        
        curr = st.top() -> right;
        st.pop();
    }

    return ans;
}