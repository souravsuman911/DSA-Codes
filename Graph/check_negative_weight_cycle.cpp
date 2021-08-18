int isNegativeWeightCycle(int n, vector<vector<int>>edges){

    int m = edges.size();
    vector<int> costArray(n, INT_MAX);
    costArray[0] = 0;
    
    for(int i = 0; i < n - 1; i ++){
        for(int j = 0; j < m; j ++){
            int u = edges[j][0];
            int v = edges[j][1];
            int cost = edges[j][2];
            
            if(costArray[u] != INT_MAX && costArray[v] > costArray[u] + cost)
                costArray[v] = costArray[u] + cost;
        }
    }
    
    for(int j = 0; j < m; j ++){
        int u = edges[j][0];
        int v = edges[j][1];
        int cost = edges[j][2];
        
        if(costArray[u] != INT_MAX && costArray[v] > costArray[u] + cost){
            return true;
        }
    }
    
    return false;
}