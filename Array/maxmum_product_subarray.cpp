long long maxProduct(int *arr, int n) {
	    
    long long gmax = INT_MIN;
    long long mini = 1;
    long long maxi = 1;
    
    
    for(int i = 0; i < n; i ++){
        
        if(arr[i] < 0)
            swap(maxi, mini);
        
        maxi = max((long long)arr[i], maxi * arr[i]);
        mini = min((long long)arr[i], mini * arr[i]);
    
        gmax = max(gmax, maxi);
    }
    
    return gmax;
}