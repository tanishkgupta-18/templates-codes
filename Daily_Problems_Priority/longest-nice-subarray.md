**Problem Link** :[longest-nice-subarray](https://leetcode.com/problems/longest-nice-subarray/)

```
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> bitFreq(32, 0);

        int l = 0, r = 0, maxLen = 0;
        
        for(int r = 0 ; r < n ; ++r){
            int num = nums[r];

            while(true){
                bool conflict = false;
                for(int bit = 0 ; bit < 32 ; ++bit){
                    if((num >> bit) & 1){
                        if(bitFreq[bit] > 0){
                            conflict = true;
                            break;
                        }
                    }
                }

                if(!conflict) break;
                
                for(int bit = 0 ; bit < 32 ; ++bit){
                    if(nums[l] >> bit & 1) bitFreq[bit]--;
                }

                l++;
            }

            for(int bit = 0 ; bit < 32 ; ++bit){
                if((num >> bit) & 1) bitFreq[bit]++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
```

## Bitmasking Approach
```
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int mask = 0;
        int maxLen = 0;
        int l = 0;

        for(int r = 0 ; r < n ; ++r){
            while((mask & nums[r]) != 0){
                mask^=nums[l];
                l++;
            }

            mask|=nums[r];
            maxLen = max(maxLen, r-l+1);
        }
        
        return maxLen;
    }
};
```