vector<int> verticalOrder(Node *root)
{
    vector<int> v1;
    if(root == NULL)
        return v1;

    queue<pair<Node*, int>> q1; 
    q1.push({root, 0});
    vector<pair<Node*, int>> v;
    map<int, queue<int>> mp;
    
    while(!q1.empty()){
        v.push_back({q1.front().first, q1.front().second});
        if(q1.front().first -> left != NULL)
            q1.push({q1.front().first -> left, q1.front().second - 1}); 
        if(q1.front().first -> right != NULL)
            q1.push({q1.front().first -> right, q1.front().second + 1});
        q1.pop();   
    }
    
    for(auto it : v){
        mp[it.second].push(it.first -> data);
    }

    for(auto it : mp){
        while(!it.second.empty()){
            v1.push_back(it.second.front());
            it.second.pop();
        }
    }
        
    return v1;

}