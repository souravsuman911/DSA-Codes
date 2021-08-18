// Find out if you can make it to the last 
// index if you start at the first index of the list.

int canReach(int arr[], int n) {
    
    int end = n - 1;

    for(int i = n - 2; i >= 0; i --){
        if(arr[i] + i >= end){
            end = i;
        }
    }
    
    if(end == 0)
        return true;
        
    return false;
}
