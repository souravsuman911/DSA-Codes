vector<int>bfsOfGraph(int V, vector<int> adj[])
{
    queue<int> q;
    vector<bool> visited(V, false);
    vector<int> ans;
    
    q.push(0);
    visited[0] = true;
    
    while(!q.empty()){
        int temp = q.front();
        ans.push_back(temp);
        q.pop();
        
        for(auto it : adj[temp]){
            if(visited[it] == false){
                q.push(it);
                visited[it] = true;
            }
        }
    }
    
    return ans;
}