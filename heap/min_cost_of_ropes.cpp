long long minCost(long long arr[], long long n) {
    
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long sum = 0;
    
    for(int i = 0; i < n; i ++){
        pq.push(arr[i]);
    }
    
    while(pq.size() != 1){
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        
        sum += first + second;
        pq.push(first + second);
    }
    
    return sum;
}