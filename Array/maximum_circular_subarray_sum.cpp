/*
Given an array arr[] of N integers arranged in a circular fashion. 
Your task is to find the maximum contiguous subarray sum.
*/

int circularSubarraySum(int arr[], int n){
    
    int sum = accumulate(arr, arr + n, 0);
    
    int localsum = 0;
    int globalsum = INT_MIN;
    
    for(int i = 0; i < n; i ++){
        localsum += arr[i];
        
        if(localsum > globalsum)
            globalsum = localsum;
            
        if(localsum < 0)
        localsum = 0;
    }
    
    int first = globalsum;
    
    localsum = 0;
    globalsum = INT_MIN;
    
    for(int i = 0; i < n; i ++)
        arr[i] *= -1;
        
    for(int i = 0; i < n; i ++){
        localsum += arr[i];
        
        if(localsum > globalsum)
            globalsum = localsum;
            
        if(localsum < 0)
        localsum = 0;
    }
    
    int second = globalsum * -1;
    
    // it means all elements were negative and we ve the return the 
    // largest -ve no(towards positive)
    if(second == sum)
        return first;
    
    return max(first, sum - second);
    
}