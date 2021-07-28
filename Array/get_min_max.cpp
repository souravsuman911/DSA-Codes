pair<int, int> getMinMax(vector<int> &arr, int l, int r){
    
    pair<int, int> minMax;
    int mid;
    pair<int, int> lMinMax,rMinMax;
    
    if(l == r){
        minMax.first = arr[l];
        minMax.second = arr[r];
        
        return minMax;
    }
    
    if(r == l + 1){
        if(arr[l] < arr[r]){
            minMax.first = arr[l];
            minMax.second = arr[r];
        }
        else{
            minMax.first = arr[r];
            minMax.second = arr[l];
        }
        
        return minMax;
    }
    
    mid = (l + r) / 2;
    
    lMinMax = getMinMax(arr, l, mid - 1);
    rMinMax = getMinMax(arr, mid, r);
    
    minMax.first = min(lMinMax.first, rMinMax.first);
    minMax.second = max(lMinMax.second, rMinMax.second);
    
    return minMax;
}