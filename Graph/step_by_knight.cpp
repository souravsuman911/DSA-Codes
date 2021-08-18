bool isValid(int x, int y, int n){
    if(x >= 0 && x < n && y >= 0 && y < n)
        return true;
        
    return false;
} 

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
{
    KnightPos[0] -= 1; KnightPos[1] -= 1; TargetPos[0] -= 1; TargetPos[1] -= 1;
    
    vector<int> dx = {1, 2, 2, 1, -1, -2, -2, -1};
    vector<int> dy = {2, 1, -1, -2, -2, -1, 1, 2};
    
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<vector<int>> q;
    int count = 0;
    
    q.push(KnightPos);
    visited[KnightPos[0]][KnightPos[1]] = true;
    
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i ++){
            int row = q.front()[0];
            int col = q.front()[1];
            q.pop();
            
            if(row == TargetPos[0] && col == TargetPos[1])
                return count;
            
            for(int i = 0; i < 8; i ++){
                if(isValid(row + dx[i], col + dy[i], n) && visited[row + dx[i]][col + dy[i]] == false){
                    q.push({row + dx[i], col + dy[i]});
                    visited[row + dx[i]][col + dy[i]] = true;
                }
            }
        }
        count ++;
    }
    
    return -1;
}
