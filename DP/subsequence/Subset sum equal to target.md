## Memoization
```
class Solution {
public:
    bool helper(int i, vector<int>& arr, int sum, vector<vector<int>>& memo) {
        if (sum == 0) return true;
        if (i == 0) return sum == arr[0];
        if (memo[i][sum] != -1) return memo[i][sum];

        bool notTake = helper(i - 1, arr, sum, memo);

        bool take = false;
        if (arr[i] <= sum)
            take = helper(i - 1, arr, sum - arr[i], memo);

        return memo[i][sum] = take || notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> memo(n, vector<int>(sum + 1, -1));
        return helper(n - 1, arr, sum, memo);
    }
};
```

## Tabulation
```
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for (int i = 0 ; i < n ; ++i) dp[i][0] = true;

        dp[0][arr[0]] = true; // you can have a check if(arr[0] <= sum)

        for (int i = 1 ; i < n ; ++i) {
            for (int j = 0 ; j <= sum ; ++j) {
                bool notTake = dp[i - 1][j];
                bool take = (arr[i] <= j ? dp[i - 1][j - arr[i]] : false);

                dp[i][j] = take || notTake;
            }
        }

        return dp[n - 1][sum];
    }
};
```