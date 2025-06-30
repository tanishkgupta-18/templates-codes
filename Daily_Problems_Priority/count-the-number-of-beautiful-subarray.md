**Problem Link**: [https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/](https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/)
## Approach 1
```
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        int currXor = 0;
        long long res = 0;
        unordered_map<int, long long> freq;
        freq[0] = 1;
        for(int i = 0 ; i < n ; ++i){
            currXor = currXor^nums[i];

            res+=freq[currXor];

            freq[currXor]++;
        }

        return res;
    }
};
```
## Approach 2
```
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        const int BITS = 20;
        vector<int> parity(BITS, 0);
        map<vector<int>, int> freq;
        freq[parity] = 1;

        long long res = 0;
        for(auto& num : nums){
            for(int bit = 0 ; bit < BITS ; ++bit){
                if((num >> bit)&1){
                    parity[bit]^=1;
                }
            }

            res += freq[parity];
            freq[parity]++;
        }

        return res;
    }
};
```