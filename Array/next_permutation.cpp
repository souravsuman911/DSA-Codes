void nextPermutation(vector<int>& arr) {
        
        int n = arr.size();
        int curr = -1;
        
        for(int i = n - 1; i >= 1; i --){
            if(arr[i] > arr[i - 1]){
                curr = i - 1;
                break;
            }
        }
        
        if(curr == -1){
            reverse(arr.begin(), arr.end());
            return;
        }
        
        int min_diff = INT_MAX;
        int swap_index;
        for(int i = n - 1; i > curr; i --){
            if(arr[i] > arr[curr]){
                if(arr[i] - arr[curr] < min_diff){
                    min_diff = arr[i] - arr[curr];
                    swap_index = i;
                }
            }
        }
        
        swap(arr[curr], arr[swap_index]);
        sort(arr.begin() + curr + 1, arr.end());
    }