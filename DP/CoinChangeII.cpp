#include<bits/stdc++.h>
using namespace std;

// coins[] =  { 25, 10, 5 } , val = 30
// o/p : 2

int getMin(vector<int> coins, int n, int val){
	vector<int> dp(val + 1);
	dp[0] = 0;

	for(int i = 1; i <= val; i ++)
		dp[i] = INT_MAX;

	for(int i = 1; i <= val; i ++){
		for(int j = 0; j < n; j ++){
			if(coins[j] <= i){
				int sub_res = dp[i - coins[j]];
				if(sub_res != INT_MAX)
					dp[i] = min(dp[i], sub_res + 1);
			}
		}
	}
	return dp[val];

	vector<int> dp(val + 1, INT_MAX);
	    dp[0]= 0;
	   
	    for(int i = 1; i <= val; i ++){
            for(int j = 0; j < n; j ++){
    	        if(coins[j] <= i){
    	            int sub_res = dp[i - coins[j]];
    	            if(sub_res != INT_MAX)
    	                dp[i] = min(dp[i], sub_res + 1);
    	        }
	        }
	    }
	    
	    return dp[val];
}

int getMinRecursive(vector<int> coins, int n, int val){
	if(val == 0)
		return 0;

	int res = INT_MAX;

	for(int i = 0; i < n; i ++){
		if(coins[i] <= val){
			int sub_res = getMinRecursive(coins, n, val - coins[i]);
			if(sub_res != INT_MAX)
				res = min(res, sub_res + 1);
		}
	}
	return res;
}

int main(){
	
	int n, val;
	cin >> n >> val;
	vector<int> coins;

	int item;
	for(int i = 0; i < n; i ++){
		cin >> item;
		coins.push_back(item);
	}
	cout << getMin(coins, n, val) << endl;
	//cout << getMinRecursive(coins, n, val) << endl;

	return 0;
}

// 3 30 25 10 5
// 4 11 9 6 5 1