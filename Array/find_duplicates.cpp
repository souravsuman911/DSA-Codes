int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 0; i < n; i ++){
            arr[arr[i] % n] += n;
        }
        
        for(int i = 1; i < n; i ++){
            if(arr[i] / n > 1)
                return i;
                
        }
        
        for(int i = 0; i < n; i ++){
            arr[i] = arr[i] % n;
        }
        
        return -1;
    }