bool find3Numbers(int arr[], int n, int x)
{
    sort(arr, arr + n);

    for(int i = 0; i < n; i ++){
        int sum = x - arr[i];
        int j = i + 1;
        int k = n - 1;
        
        while(j < k){
            if(arr[j] + arr[k] == sum)
                return true;
            else if(arr[j] + arr[k] < sum)
                j ++;
            else
                k --;
        }
    }

    return false;
}