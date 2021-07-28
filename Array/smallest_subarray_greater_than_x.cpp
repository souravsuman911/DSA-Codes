int sb(int arr[], int n, int k)
    {
        int minm = n;
        long long sum = 0;
        
        int j = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(sum > k){
                //cout << sum << endl;
                while(sum - arr[j] > k){
                    sum -= arr[j];
                    j ++;
                }
                //cout << "i : " << i << "j : " << j << endl;
                minm = min(minm, i - j);
            }
        }
        
        return minm + 1;
        
    }