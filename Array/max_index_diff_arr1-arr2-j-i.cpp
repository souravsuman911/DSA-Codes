int maxIndexDiff(int arr[], int n) 
{ 
    vector<int> lMin, rMax;
    int minm = INT_MAX, maxm = INT_MIN, res = INT_MIN;
    
    for(int i = 0; i < n; i ++){
        minm = min(minm, arr[i]);
        lMin.push_back(minm);
    }
    
    for(int i = n - 1; i >= 0; i --){
        maxm = max(maxm, arr[i]);
        rMax.push_back(maxm);
    }
    reverse(rMax.begin(), rMax.end());
    
    int i = 0, j = 0;
    while(i < n && j < n){
        if(rMax[j] >= lMin[i]){
            res = max(res, j - i);
            j ++;
        }
        else
            i ++;
    }
    
    
    return res;
}