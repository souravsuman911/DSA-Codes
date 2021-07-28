class Solution
{
    public:
    //Function to find the number of islands.
    void addEdges(vector<vector<char>> &grid, vector<int> adj[], int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = -1; i <= 1; i ++){
            for(int j = -1; j <= 1; j ++){
                if(row + i < 0 || row + i > m - 1 ||
                   col + j < 0 || col + j > n - 1 ||
                   (i == 0 && j == 0)){
                       continue;  
                }
                else if(grid[row + i][col + j] == '1'){
                    int u = (row * n) + col;
                    int v = ((row + i) * n) + (col + j);

                    adj[u].push_back(v);
                }
            }
        }
    }
    
    void BFS(vector<int> adj[], int src, vector<bool> &visited){
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
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        
        int n = row * col;
        vector<int> adj[n];
        
        for(int i = 0; i < row; i ++){
            for(int j = 0; j < col; j ++){
                if(grid[i][j] == '1')
                    addEdges(grid, adj, i, j);
            }   
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i ++){
            int r = i / col;
            int c = i % col;
            if(!visited[i] && grid[r][c] == '1'){
                BFS(adj, i, visited);
                count ++;
            }
        }
        
        return count;
    }
};