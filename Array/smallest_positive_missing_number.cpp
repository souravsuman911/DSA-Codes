int missingNumber(int arr[], int n) 
{ 
    if(n == 1){
        if(arr[0] != 1)
            return 1;
        else
            return 2;
    }
    
    bool flag = false;
    bool flag2 = false;
    
    for(int i = 0; i < n; i ++){
        if(arr[i] == 1){
            flag = true;
            break;
        }
    }
    if(flag == false)
        return 1;
        
    for(int i = 0; i < n; i ++){
        if(arr[i] == n)
            flag2 = true;
            
        if(arr[i] <= 0)
            arr[i] = 1;
    }
    
    for(int i = 0; i < n; i ++){
        if(abs(arr[i]) >= n)
            continue;
            
        if(arr[abs(arr[i])] > 0)
            arr[abs(arr[i])] *= -1;
    }
    
    for(int i = 1; i < n; i ++){
        if(arr[i] > 0)
            return i;
    }
    
    if(flag2 == false)
        return n;
        
    return n + 1;
} 