int maxProfit(vector<int>& arr) {
        
    int n = arr.size();
    int ans = INT_MIN;
    
    int maxm = INT_MIN;
    for(int i = n - 1; i >= 0; i --){
        maxm = max(maxm, arr[i]);
        ans = max(ans, maxm - arr[i]);
    }
    
    return ans;
}

// You want to maximize your profit by 
// choosing a single day to buy one stock 
// and choosing a different day in the 
// future to sell that stock.