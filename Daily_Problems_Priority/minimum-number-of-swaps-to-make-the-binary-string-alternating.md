**Problem Link**: [minimum-number-of-swaps-to-make-the-binary-string-alternating](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating)

## Approach 1

```
class Solution {
public:
    int n;
    string creator(char initiator, char supp){
        string t = "";

        for(int i = 0 ; i < n ; i++){
            if(i%2==0) t+=initiator;
            else t+=supp;
        }

        return t;
    }

    int counter(string& s, string& t){
        int cnt = 0;
        for(int i = 0 ; i < n ; ++i){
            if(s[i] != t[i]) cnt++;
        }

        return cnt/2;
    }

    int minSwaps(string s) {
        n = s.size();

        int ones = 0, zero = 0;
        for(auto& c : s) (c == '1')? ones++ : zero++;

        if(abs(ones - zero) > 1) return -1;

        int count = 0;
        if(ones > zero){
            string t = creator('1', '0');
            count += counter(s, t);
        } else if(ones < zero){
            string t = creator('0', '1');
            count += counter(s, t);
        } else{
            string x = creator('1', '0');
            string y = creator('0', '1');

            count += min(counter(s, x), counter(s, y));
        }

        return count;
    }
};
```

## Approach2
```
class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');
        int zeros = n - ones;

        // Alternating is impossible if difference is more than 1
        if (abs(ones - zeros) > 1) return -1;

        // Count mismatches for both patterns
        // Pattern A: starts with '0'
        int mismatches_start_with_0 = 0;
        for (int i = 0; i < n; ++i) {
            char expected = (i % 2 == 0) ? '0' : '1';
            if (s[i] != expected) mismatches_start_with_0++;
        }

        // Pattern B: starts with '1'
        int mismatches_start_with_1 = 0;
        for (int i = 0; i < n; ++i) {
            char expected = (i % 2 == 0) ? '1' : '0';
            if (s[i] != expected) mismatches_start_with_1++;
        }

        // Only one pattern is valid if ones and zeros differ
        if (ones > zeros) return mismatches_start_with_1 / 2;
        if (zeros > ones) return mismatches_start_with_0 / 2;

        // If equal, choose minimum
        return min(mismatches_start_with_0, mismatches_start_with_1) / 2;
    }
};
```