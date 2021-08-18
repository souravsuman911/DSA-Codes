int tour(petrolPump p[],int n)
{
    int count = 0;
    int start = 0, sum = 0;
    
    for(int i = 0; i < n; i ++)
        p[i].petrol = p[i].petrol - p[i].distance;
    
    for(int i = 0; i < 2 * n; i ++){
        int idx = i % n;
        count ++;
        sum += p[idx].petrol;
        
        if(idx == start  && sum >= 0 && count == n + 1){
            return start;
        }
        
        if(sum < 0){
            start = idx + 1;
            count = 0;
            sum = 0;
        }
    }
    
    return -1;
}