void traverse(Node* root, int n, stack<Node*> &st){
    if(root == NULL)
        return;
        
    st.push(root);
    
    if(root -> data == n){
        return;
    }
    traverse(root -> left, n, st);
    traverse(root -> right, n, st);
    if(st.top() -> data != n)
        st.pop();
}

Node* lca(Node* root ,int n1 ,int n2 ){
    
    stack<Node*> s1;
    stack<Node*> s2;
    
    traverse(root, n1, s1);
    traverse(root, n2, s2);
    
    vector<Node*> v1;
    vector<Node*> v2;
    
    while(!s1.empty()){
        v1.insert(v1.begin(), s1.top());
        s1.pop();
    }
    
    while(!s2.empty()){
        v2.insert(v2.begin(), s2.top());
        s2.pop();
    }
    
    int n = min(v1.size(), v2.size());
    Node* prev = root;
    
    for(int i = 0; i < n; i ++){
        if(v1[i] -> data != v2[i] -> data)
            return prev;
        
        prev = v1[i];
    }
    
    return prev;
}