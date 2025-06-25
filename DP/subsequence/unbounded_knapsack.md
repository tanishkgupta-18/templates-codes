Find the maximum total value that can be achieved by putting items into the knapsack, where you can take any item any number of times.
### Memoization
```
int f(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& memo) {
    if(i == 0){
    	return (W / wt[0]) * val[0]; //  take as many as fit
    }
    
    if(memo[i][W]!=-1) return memo[i][W];
    int notTake = f(i-1, W, wt, val, memo);
    int take = 0;
    if(wt[i] <= W)
    take = val[i] + f(i, W - wt[i], wt, val, memo);
    
    return memo[i][W] = max(take, notTake);
}

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> memo(n, vector<int>(W+1, -1));
    
    return f(n-1, W, wt, val, memo);
}
```

### Tabulation

```
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    
    for(int w = 0 ; w <= W ; ++w) dp[0][w] = (w/wt[0])*val[0];
    
    for(int i = 1 ; i < n ; ++i){
    	for(int w = 0 ; w <= W ; ++w){
    		int notTake = dp[i-1][w];
    		int take = (wt[i] <= w)? val[i] + dp[i][w-wt[i]] : 0;
    		
    		dp[i][w] = max(take, notTake);
    	}
    }
    
    return dp[n-1][W];
}
```