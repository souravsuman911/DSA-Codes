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
    
    int minm = INT_MAX;
    int minIdx;
    for(int i = n - 1; i > curr; i --){
        if(arr[i] > arr[curr]){
            if(arr[i] < minm){
                minm = arr[i];
                minIdx = i;
            }
        }
    }
            
    swap(arr[curr], arr[minIdx]);
    sort(arr.begin() + curr + 1, arr.end());
}