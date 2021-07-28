class Solution {
public:
    
    void addEdges(vector<vector<int>> &adj, int u, int v){
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
      
    void BFS(vector<vector<int>> &adj, int src, vector<bool> &visited){
        
        queue<int> q;
        q.push(src);
        visited[src] = true;
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            for(auto it : adj[temp]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = true;
                }
            }
        }   
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n - 1)
            return -1;
        
        vector<vector<int>> adj(n);
        
        for(auto it : connections)
            addEdges(adj, it.front(), it.back());
        
        int count = 0;
        vector<bool> visited(n, false);
        for(int it = 0; it < n; it ++){
            if(!visited[it]){
                BFS(adj, it, visited);
                count ++;
            }
        }
        
        return count - 1;
    }
};