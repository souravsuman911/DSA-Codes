/*
            /
            \
            /
            \
*/


vector <int> zigZagTraversal(Node* root)
{
    vector<int> v;
    if(root == NULL)
        return v;
	stack<Node*> s1; s1.push(root);
	stack<Node*> s2;
	
	while(!s1.empty() || !s2.empty()){
	    while(!s1.empty()){
	        v.push_back(s1.top() -> data);
	        if(s1.top() -> left != NULL)
	            s2.push(s1.top() -> left);
	        if(s1.top() -> right != NULL)
	            s2.push(s1.top() -> right);
	        s1.pop();
	    }
	    
	    while(!s2.empty()){
	        v.push_back(s2.top() -> data);
	        if(s2.top() -> right != NULL)
	            s1.push(s2.top() -> right);
	        if(s2.top() -> left != NULL)
	            s1.push(s2.top() -> left);
	        s2.pop();
	    }
	}
	
	return v;
}