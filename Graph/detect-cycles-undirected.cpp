class Solution 
{
    public:
	bool DFS(int src, int parent, vector<int> adj[], vector<bool> &visited)
	{
		visited[src] = true;
		
		for(auto it: adj[src])
		{
			if(it == parent)
				continue;
				
			if(visited[it])
				return true;
			if(DFS(it, src, adj, visited))
				return true;
		}
		return false;
	}
	
	bool isCycle(int n, vector<int>adj[])
	{
		vector<bool>visited(n, false);
		
		for(int i = 0; i < n; i++)
		{
			if(!visited[i]){
				if(DFS(i, -1, adj, visited))
				    return true;
			}
		}
		return false;
	}
};