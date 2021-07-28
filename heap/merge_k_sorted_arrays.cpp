void print(priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>> > > pq){
    while(!pq.empty()){
        cout << pq.top().first << " : " << pq.top().second.first << " : " << pq.top().second.second << "    ";
        pq.pop();
    }cout << endl;
}

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>> > > pq;
    vector<int> res;
    int row, col;
    
    for(int i = 0; i < k; i ++)
        pq.push({arr[i][0], {i, 0}});
        
    
    while(!pq.empty()){
        row = pq.top().second.first;
        col = pq.top().second.second;
        col ++;
        
        res.push_back(pq.top().first);
        pq.pop();   
        
        if(col < k){
            pq.push({ arr[row][col], {row, col} });
        }
    }
    
    return res;
    
}