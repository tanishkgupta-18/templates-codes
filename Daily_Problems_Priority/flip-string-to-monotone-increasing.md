**Problem Link** : [https://leetcode.com/problems/flip-string-to-monotone-increasing/](https://leetcode.com/problems/flip-string-to-monotone-increasing/)
## Most Optimal Approach
```
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int flips = 0, ones = 0;
        for(char c : s){
            if(c == '1'){
                ones++;
            } else{
                flips++;
                flips = min(flips, ones);
            }
        }

        return flips;
    }
};
```
## Initial Approach
```
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> ones(n + 1, 0); // prefix sum of 1s

        for (int i = 0; i < n; ++i) {
            ones[i + 1] = ones[i] + (s[i] == '1'? 1 : 0);
        }

        int ans = n;
        for(int i = 0 ; i <= n ; ++i){
            int flips = ones[i] + (n - i - (ones[n] - ones[i]));
            ans = min(ans, flips);
        }

        return ans;
    }
};
```