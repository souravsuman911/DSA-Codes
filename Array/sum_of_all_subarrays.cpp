// brute force O(n2)
long long subarraySum(long long arr[], long long n)
{
    int temp;
    int sum = 0;
    for(int i = 0; i < n; i ++){
        temp = 0;
        for(int j = i; j < n; j ++){
            temp += arr[j];
            sum += temp;
        }
    }
    
    return sum;
}

// better solution with observation - o(n)
// every element occurs (i + 1) * (n - 1) times

long long subarraySum(long long arr[], long long n)
{
    int mod = 1000000007;
    long long sum = 0;
    for(int i = 0; i < n; i ++){
        sum = (sum + arr[i] * (i + 1) * (n - i)) % mod;
    }
    
    return sum;
}