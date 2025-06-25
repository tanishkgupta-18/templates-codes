**Problem Link**[https://leetcode.com/problems/shortest-common-supersequence/](https://leetcode.com/problems/shortest-common-supersequence/)

```
void shortestcommonSuperSeq(string& s1, string& s2){
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
	
	int i = n, j = m;
	string scs = "";
	while(i > 0 && j > 0){
		if(s1[i-1] == s2[j-1]){
			scs += s1[i-1];
			i--; j--;
		}else if(dp[i-1][j] > dp[i][j-1]){
			scs+=s1[i-1];
			i--;
		}else{
			scs+=s2[j-1];
			j--;
		}
	}
	
	while(i>0){
		scs += s1[i-1];
		i--;
	}
	
	while(j>0){
		scs += s2[j-1];
		j--;
	}
	reverse(scs.begin(), scs.end()); // since we built it backwards
	
	cout << scs << '\n';
}
```