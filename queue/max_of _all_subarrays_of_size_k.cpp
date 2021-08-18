vector <int> max_of_subarrays(int *arr, int n, int k)
{
    deque<int> q;
    vector<int> ans;
    
    for(int i = 0; i < k; i ++){
        while(!q.empty() && arr[q.back()] <= arr[i])
            q.pop_back();
        q.push_back(i);
    }
    
    for(int i = k; i < n; i ++){
        ans.push_back(arr[q.front()]);
        while(!q.empty() && q.front() <= i - k)
            q.pop_front();
            
        while(!q.empty() && arr[q.back()] <= arr[i])
            q.pop_back();
            
        q.push_back(arr[i]);
    }
    ans.push_back(q.front());
    
    return ans;
}