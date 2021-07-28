int recursion(vector<int> &arr, vector<vector<vector<int>>> &dp, int pos, int t, int bought){
        
        if(pos >= arr.size() || t == 0)
            return 0;
        if(dp[bought][t][pos] != -1)
            return dp[bought][t][pos];
        
        int result = recursion(arr, dp, pos + 1, t, bought); // SKIP
        if(bought)
            result = max(result, recursion(arr, dp, pos + 1, t - 1, false) + arr[pos]); // BUY
        else
            result = max(result, recursion(arr, dp, pos + 1, t, true) - arr[pos]); // SELL
        
        dp[bought][t][pos] = result;
        return result;
    }
    
    int maxProfit(vector<int>& arr) {
        
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(3, vector<int>(arr.size(), -1)));
        
        int res = recursive(arr, dp, 0, 2, false);
        return res;
        
    }

/*

Find the maximum profit you can achieve. 
You may complete at most two transactions.
Note: You may not engage in multiple 
transactions simultaneously (i.e., 
you must sell the stock before you buy again).

*/