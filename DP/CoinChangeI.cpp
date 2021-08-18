#include<bits/stdc++.h>
using namespace std;

int getCountDP(vector<int> arr, int n, int sum){
    int dp[sum + 1][n + 1];

    for(int i = 0; i <= n; i ++)
        dp[0][i] = 1;

    for(int i = 1; i <= sum; i ++)
        dp[i][0] = 0;

    for(int i = 1; i <= sum; i ++){
        for(int j = 1; j <= n; j ++){
            dp[i][j] = dp[i][j - 1];

            if(i >= arr[j - 1])
                dp[i][j] += dp[i - arr[j - 1]][j];
        }
    }
    return dp[sum][n];
}

int getCountRecursiveDP(vector<int> coins, int n, int sum, vector<vector<int>> &dp){
	if(dp[sum][n] != -1)	return dp[sum][n];

	if(sum == 0 || n == 0)
		return dp[sum][n];

	dp[sum][n] = getCountRecursiveDP(coins, n - 1, sum, dp);

	if(sum >= coins[n - 1])
		dp[sum][n] += getCountRecursiveDP(coins, n, sum - coins[n - 1], dp);

	return dp[sum][n];
}

int getCountRecursive(vector<int> arr, int n, int sum){
	if(sum == 0)
		return 1;

	if(n == 0)
		return 0;

	int res = getCountRecursive(arr, n - 1, sum);

	if(sum >= arr[n - 1])
		res += getCountRecursive(arr, n, sum - arr[n - 1]); 
	
	return res;
}

int main(){

    vector<int> arr = {2, 5, 3, 6}; // {1, 2, 3, 4};
    int n = arr.size();
    int sum = 10; // 4;

    cout << getCountDP(arr, n, sum) << endl;

	return 0;
}

