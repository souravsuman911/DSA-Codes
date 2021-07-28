vector<int> kLargest(int arr[], int n, int k) {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;
    
    for(int i = 0; i < k; i ++)
        pq.push(arr[i]);
        
    for(int i = k; i < n; i ++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    
    reverse(res.begin(), res.end());
    
    return res;
}