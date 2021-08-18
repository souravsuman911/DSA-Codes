static bool myComp(Job a, Job b){
    return (a.profit > b.profit);
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    vector<int> ans;
    int profit = 0;
    int count = 0, maxDead = 0;
    
    sort(arr, arr + n, myComp);
    
    for(int i = 0; i < n; i ++){
        maxDead = max(maxDead, arr[i].dead);
    }
    
    vector<bool> deadline(maxDead, false);
    
    for(int i = 0; i < n; i ++){
        int d = arr[i].dead - 1;
        
        while(d >= 0 && deadline[d] == true)
            d --;
            
        if(d >= 0){
            count ++;
            profit += arr[i].profit;
            deadline[d] = true;
        }
    }
    
    ans.push_back(count);
    ans.push_back(profit);
    
    return ans;
}