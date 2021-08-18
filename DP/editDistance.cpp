#include<bits/stdc++.h>
using namespace std;

int editDistance(string x, string y, vector<vector<int>> &dp){
	int m = x.size();
	int n = y.size();

	for(int i = 0; i <= m; i ++)
		dp[i][0] = i;
	
	for(int i = 0; i <= n; i ++)
		dp[0][i] = i;

	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= n; j ++){
			if(x[i- 1] == y[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else{
				dp[i][j] = 1 + min({dp[i][j - 1],
				dp[i - 1][j - 1],
				dp[i - 1][j]});
			} 
		}
	}

	return dp[m][n];
}

int editdistanceRecursiveDP(string x, string y, int m, int n, vector<vector<int>> &dp){
        
	if(dp[m][n] != -1)
		return dp[m][n];
		
	if(m == 0)  
		dp[m][n] = n;   
	if(n == 0)  
		dp[m][n] = m;
	
	if(x[m - 1] == y[n - 1])
		dp[m][n] = editdistanceRecursiveDP(x, y, m - 1, n - 1, dp);
	else
		dp[m][n] = 1 + min({
			editdistanceRecursiveDP(x, y, m - 1, n, dp), 
			editdistanceRecursiveDP(x, y, m, n - 1, dp), 
			editdistanceRecursiveDP(x, y, m - 1, n - 1, dp)
		});
		
	return dp[m][n];
}

int editDistanceRecursive(string x, string y, int m, int n){

	if(m == 0)	return n;
	if(n == 0)	return m;

	if(x[m - 1] == y[n - 1])
		return editDistanceRecursive(x, y, m - 1, n - 1);
	else
		return 1 + min({editDistanceRecursive(x, y, m - 1, n),
		editDistanceRecursive(x, y, m - 1, n - 1),
		editDistanceRecursive(x, y, m, n - 1)});
}

int main(){
	
	string x = "CAT";
	string y = "CUT";

	int m = x.size();
	int n = y.size();

	vector<vector<int>> dp(m + 1, vector<int> (n + 1));

	cout << editDistance(x, y, dp) << endl;
	return 0;
}