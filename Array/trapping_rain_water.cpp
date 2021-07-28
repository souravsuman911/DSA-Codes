int tpWater(int arr[], int maxi){
        
    int sum = 0;   
    int localMin = 0;
    for(int i = 0; i < maxi; i ++){
        if(arr[i] > arr[localMin]){
            localMin = i;
        }
        else{
            sum += (arr[localMin] - arr[i]);
        }
    }
    
    return sum;
}

int trappingWater(int arr[], int n){
    
    int maxm = INT_MIN;
    int maxi = 0;
    
    for(int i = 0; i < n; i ++){
        if(arr[i] >= maxm){
            maxm = arr[i];
            maxi = i;
        }
    }
    
    int res = tpWater(arr, maxi);
    reverse(arr, arr + n);
    maxi = n - maxi - 1;
    res += tpWater(arr, maxi);
    
    return res;
}