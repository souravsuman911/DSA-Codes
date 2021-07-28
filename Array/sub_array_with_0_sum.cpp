bool subArrayExists(int arr[], int n)
    {
        int sum = accumulate(arr, arr + n, 0);
        
        map<int, int> mp;
        vector<int> left_sum;
        left_sum.push_back(sum);
        
        for(int i = 0; i < n; i ++){
            if(sum == 0 || arr[i] == 0)
                return true;
                
            sum -= arr[i];
            left_sum.push_back(sum);
        }
        
        for(int i = 0; i <= n; i ++){
            mp[left_sum[i]] ++;
            
            if(mp[left_sum[i]] == 2)
                return true;
        } 
        
        return false;
    }