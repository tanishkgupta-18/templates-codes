## Longest Common Subsequence

**dp[i][j]** denotes longest common subsequence between s1(0...i-1) and s2(0...j-1)

```
int LCS(string& s1, string& s2){
	int n = s1.size(), m = s2.size();
	
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	return dp[n][m];
}
```

## Printing LCS

you need to backtrack from dp[n][m] to dp[0][0]

```
void printLCS(string& s1, string& s2){
	int n = s1.size(), m = s2.size();
	
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	int length = dp[n][m];
	int i = n, j = m;
	string lcs = "";
	while(i > 0 && j > 0){
		if(s1[i-1] == s2[j-1]){
			lcs += s1[i-1];
			i--; j--;
		}else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}else{
			j--;
		}
	}
	reverse(lcs.begin(), lcs.end()); // since we built it backwards
	
	cout << lcs << '\n';
}
```
## Variations of LCS
- longest palindromic substring use  LCS(s, reverse(s))
- minimum insertion steps to make string palindrome use LCS and return n - dp[n][n] **(denotes unsymmetrical pairs)**
- Minimum Insertions/Deletions to Convert String
- Shortest Common Supersequence