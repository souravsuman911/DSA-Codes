int getPairsCount(int arr[], int n, int k) {
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i ++)
            mp[arr[i]] ++;
            
        int count = 0; 
        for(int i = 0; i < n; i ++){
            if(arr[i] == k - arr[i])
                count += -- mp[arr[i]];
            else{
                count += mp[k - arr[i]];
                mp[arr[i]] --;
            }
        }
        
        return count;
    }