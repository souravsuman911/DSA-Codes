#include <bits/stdc++.h>
using namespace std;

// i/p : n = 5 , a = 1, b = 2, c = 3;
// o/p : 5

int maxCuts(int n, int a, int b, int c){
	if(n < 0) return -1;
	if(n == 0) return 0;

	int res = max({maxCuts(n - a, a, b, c),
				maxCuts(n - b, a, b, c),
				maxCuts(n - b, a, b, c)});

	if(res == -1)
		return res;

	return res + 1;
}

int maxCutsDP(int n, int a, int b, int c){
    int dp[n + 1];
    dp[0] = 0;

    for(int i = 1; i <= n; i ++){
        dp[i] = -1;

        if(i - a >= 0)
            dp[i] = max(dp[i], dp[i - a]);

        if(i - b >= 0)
            dp[i] = max(dp[i], dp[i - b]);

        if(i - c >= 0)
            dp[i] = max(dp[i], dp[i - c]);

        if(dp[i] != -1)
            dp[i] ++;
    }
    return dp[n];
}

int maxCutsArray(int n, vector<int> &coins){
	int m = coins.size();
	vector<int> dp(n + 1, -1);
	dp[0] = 0;

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j ++){
			if(i - coins[j] >= 0)
				dp[i] = max(dp[i], dp[i - coins[j]]);
		}
		if(dp[i] != -1)
			dp[i] ++;
	}

	return dp[n];
}

int main()
{
    int n;
	int a, b, c;

	cin >> n >> a >> b >> c;

	cout << maxCuts(n, a, b, c) << endl;
	cout << maxCutsDP(n, a, b, c) << endl;

	return 0;
}
// 23 12 11 13
// 5 1 2 3
