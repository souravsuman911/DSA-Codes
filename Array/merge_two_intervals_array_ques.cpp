static int myComp(vector<int> v1, vector<int> v2){
    return v1[0] < v2[0];
}

vector<vector<int>> merge(vector<vector<int>>& arr) {
    
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end(), myComp);
    
    int n = arr.size();
    for(int i = 0; i < n - 1; i ++){
        if(arr[i][1] >= arr[i + 1][0]){
            int minm = min(arr[i][0], arr[i + 1][0]);
            int maxm = max(arr[i][1], arr[i + 1][1]);
            
            arr[i + 1][0] = minm;
            arr[i + 1][1] = maxm;
        }
        else{
            ans.push_back({arr[i][0], arr[i][1]});
        }
    }
    
    ans.push_back({arr[n - 1][0], arr[n - 1][1]});
    
    return ans;   
}