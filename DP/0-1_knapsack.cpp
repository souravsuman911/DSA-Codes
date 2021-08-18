int ksack(int W, int wt[], int val[], int n, vector<vector<int>> &dp){
    if(dp[n][W] != -1)  return dp[n][W];
        
    if(wt[n - 1] > W)
        dp[n][W] = ksack(W, wt, val, n - 1, dp);
    else{
        dp[n][W] = max(ksack(W, wt, val, n - 1, dp), 
        val[n - 1] + ksack(W - wt[n - 1], wt, val, n - 1, dp));
    }    
    
    return dp[n][W];
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
    vector<vector<int>> dp(n + 1, vector<int> (W + 1, -1));
    
    for(int i = 0; i <= n; i ++)
        dp[i][0] = 0;
    
    for(int i = 0; i <= W; i ++)
        dp[0][i] = 0;
        
    ksack(W, wt, val, n, dp);
    
    return dp[n][W];
}