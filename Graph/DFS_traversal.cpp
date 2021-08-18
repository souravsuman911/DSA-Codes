void DFS(vector<int> adj[],int src, vector<bool> &visited, vector<int> &ans){
    visited[src] = true;
    ans.push_back(src);
    
    for(auto it : adj[src]){
        if(!visited[it])
            DFS(adj, it, visited, ans);
    }
}

// main func
vector<int>dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<int> ans;
    
    DFS(adj, 0, visited, ans);
    
    return ans;
}