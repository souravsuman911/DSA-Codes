vector<vector<int> > stockBuySell(vector<int> arr, int n){
    
    int i = 0, j, k = 0;
    bool flag = true;  // to check whether we are in buying state or not
    vector<vector<int>> ans;
    
    for(j = 0; j < n - 1; j ++){
        if(arr[j] >= arr[j + 1]){
            if(arr[j] > arr[i]){
                vector<int> curr = {i, j};
                ans.push_back(curr);
                i = j + 1;
                flag = false;
            }
            else if(arr[j] == arr[i] && j != i)
                i = j;
            else
                i = j + 1;
        } 
        else{
            flag = true;
        }
    }
    
    if(flag == true && arr[j] > arr[i]){
        vector<int> curr = {i, j};
        ans.push_back(curr);
    }
    
    return ans;
}