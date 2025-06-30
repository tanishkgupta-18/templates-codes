**Problem Link** [https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/description/](https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/description/)

### Key Part : Is to count the subsequence i.e solve function which greedily counts the subsequences another approach could be the prefix array.

```
class Solution {
public:
    long long solve(string& t, string& pattern){
        long long ans = 0, count = 0;
        for(int i = 0 ; i < t.size() ; ++i){
            if(t[i] == pattern[0]) count++;
            else if(t[i] == pattern[1]) ans += count;
        }

        return ans;
    }

    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
    
        long long cnt1 = 0, cnt2 = 0;
        for(int i = 0 ; i < n ; ++i){
            if(text[i] == pattern[0]) cnt1++;
            if(text[i] == pattern[1]) cnt2++;
        }

        if(cnt1 == 0 && cnt2 == 0) return 0;

        if(pattern[0] == pattern[1]){
            return cnt1*1LL*(cnt1+1)/2;
        }
        
        long long ans = 0;
        string x = pattern[0] + text;
        string y = text + pattern[1];

        ans = max(solve(x, pattern), solve(y, pattern));
        
        return ans;
    }
};
```
### Prefix Array Approach
```
class Solution {
public:
    long long solve(string& t, string& pattern, vector<int>& pref){
        long long ans = 0;
        for(int i = 0 ; i < t.size() ; ++i){
            if(t[i] == pattern[0]) ans = ans + pref[i+1];
        }

        return ans;
    }

    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
    
        long long cnt1 = 0, cnt2 = 0;
        for(int i = 0 ; i < n ; ++i){
            if(text[i] == pattern[0]) cnt1++;
            if(text[i] == pattern[1]) cnt2++;
        }

        if(cnt1 == 0 && cnt2 == 0) return 0;

        if(pattern[0] == pattern[1]){
            return cnt1*1LL*(cnt1+1)/2;
        }
        
        long long ans = 0;
        vector<int> pref(n+1, 0);
        
        if(text[n-1] == pattern[1]) pref[n] = 1;
        for(int i = n-1 ; i >= 1 ; --i){
            if(text[i-1] == pattern[1]){
                pref[i] = pref[i+1] + 1;
            }else{
                pref[i] = pref[i+1];
            }
        }

        ans = max(cnt2 + solve(text, pattern, pref), cnt1 + solve(text, pattern, pref));

        return ans;
    }
};
```