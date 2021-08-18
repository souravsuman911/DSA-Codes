int findZeroes(int arr[], int n, int m) {
    int l = 0, r = 0, wSize = 0, count = 0;
    
    while(r < n){
        if(count <= m){
            if(arr[r] == 0)
                count ++;
            r ++;
        }
        else{
            if(arr[l] == 0)
                count --;
            l ++;
        }
        
        if(r - l > wSize && count <= m)
            wSize = r - l;
    }
    
    return wSize;
}