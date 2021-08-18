#include<bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int m, int n, vector<vector<int>> &memo){
	if(memo[m][n] != -1) return memo[m][n];

 	if(m == 0 || n == 0)
		memo[m][n] = 0;

	else if(x[m - 1] == y[n - 1]){
		memo[m][n] = 1 + lcs(x, y, m - 1, n - 1, memo);
	}
	else
		memo[m][n] = max(lcs(x, y, m - 1, n, memo), lcs(x, y, m, n - 1, memo));

	return memo[m][n];
}

int main(){

	string a = "babbab";
	string b = "abaaba";
	int m = a.size();
	int n = b.size();
	vector<vector<int>> memo(m + 1, vector<int> (n + 1, -1));

	lcs(a, b, m, n, memo);

	cout << memo[m][n] << endl;
	
	return 0;

}

// #include<bits/stdc++.h>
// using namespace std;

// int lcs(string x, string y){
// 	int m = x.size();
// 	int n = y.size();

// 	vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));

// 	for(int i = 0; i < dp.size(); i ++){
// 		dp[i][0] = 0;
// 		dp[0][i] = 0;
// 	}

// 	for(int i = 0; i < m; i ++){
// 		for(int j = 0; j < n; j ++){
// 			if(x[i] == y[j]){
// 				dp[i + 1][j + 1] = dp[i][j] + 1;
// 			}
// 			else{
// 				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
// 			}
// 		}
// 	}

// 	return dp[m][n];

// 	for(auto it : dp){
// 		for(auto it1 : it)
// 			cout << it1 << " ";
// 		cout << endl;
// 	}cout << endl;

	// int i = m;
	// int j = n;
	// string ans = "";
	// while(i >= 1 && j >= 1){
	// 	if(x[i - 1] == y[j - 1]){
	// 		ans += x[i - 1];
	// 		i --, j --;
	// 	}
	// 	else if(dp[i][j] == dp[i][j - 1]){
	// 		j --;
	// 	}
	// 	else{
	// 		i --;
	// 	}
	// }

	// return ans;
// }


// int main(){
// 	string a = "babbab";
// 	string b = "abaaba";

// 	cout << lcs(a, b) << endl;

// 	return 0;
// }