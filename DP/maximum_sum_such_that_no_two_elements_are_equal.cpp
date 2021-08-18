int findMaxSumUtil(int arr[], int n, int i, vector<int> &dp){
    if(dp[i] != -1)
        return dp[i];
    
    if(i >= n)
        return 0;
        
    if(i == n - 1)
        return dp[i] = arr[i];
        
    if(i == n - 2)
        return dp[i] = max(arr[i], arr[i + 1]);

    int case1 = arr[i] + findMaxSumUtil(arr, n, i + 2, dp);
    int case2 = findMaxSumUtil(arr, n, i + 1, dp);

    dp[i] = max(case1, case2);
    
    return dp[i];
}
    
int FindMaxSum(int arr[], int n)
{
    vector<int> dp(n, -1);
    
    return findMaxSumUtil(arr, n, 0, dp);
}