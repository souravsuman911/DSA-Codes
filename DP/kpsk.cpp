/* Read input from STDIN. Print your output to STDOUT*/
#include<bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int m, int n, vector<vector<int>> &dp){
	if(dp[m][n] != -1) return dp[m][n];

 	if(m == 0 || n == 0)
		dp[m][n] = 0;

	else if(x[m - 1] == y[n - 1]){
		dp[m][n] = 1 + lcs(x, y, m - 1, n - 1, dp);
	}
	else
		dp[m][n] = max(lcs(x, y, m - 1, n, dp), lcs(x, y, m, n - 1, dp));

	return dp[m][n];
}

int main(int argc, char *a[])
{
    string x;
    cin >> x;
    int m = x.length();
    
    int t;
    cin >> t;

    while(t --){

        string y;
        cin >> y;
        int n = y.length();

        vector<vector<int>>dp (m + 1, vector<int> (n + 1, -1));

        for(int i = 0; i <= m; i ++)
            dp[i][0] = 0;
        
        for(int i = 0; i <= n; i ++)
            dp[0][i] = 0;
        
        lcs(x, y, m, n, dp);
        

        for(auto it : dp){
            for(auto it1 : it)
                cout << it1 << " ";
            cout << endl;
        }cout << endl;

        if(dp[m][n] == n)
            cout << "POSITIVE" << endl;
        else
            cout << "NEGATIVE" << endl;

    }

    return 0;
}
