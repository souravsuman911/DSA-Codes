pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
        
    priority_queue< pair<int, pair<int, int>>, vector< pair<int, pair<int, int>> >, greater< pair<int, pair<int, int>> > > pq;
    int minm, maxm = INT_MIN, row, col;
    pair<int, int> ans;
    ans.first = 0;
    ans.second = INT_MAX;
    
    for(int i = 0; i < k; i ++){
        maxm = max(maxm, arr[i][0]);
        pq.push({arr[i][0], {i, 0}});
    }
        
    while(!pq.empty()){
        
        row = pq.top().second.first;
        col = pq.top().second.second;
        
        minm = pq.top().first;
        
        if((maxm - minm) < (ans.second - ans.first)){
            ans.first = minm;
            ans.second = maxm;
        }
        
        pq.pop();
        if(col + 1 < n)
            pq.push({ arr[row][col + 1], {row, col + 1} });
        else
            break;
        
        maxm = max(maxm, arr[row][col + 1]);
    }
        
    return ans;
}