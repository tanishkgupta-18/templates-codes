**Problem Link** :[https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/](https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/)
```
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0 ; i < n ; ++i){
            int g = 0;
            for(int j = i ; j < n ; ++j){
                g = __gcd(g, nums[j]);
                if(g < k) break; // GCD can only stay the same or decrease as you add more elements.
                if(g == k) count++;
            }
        }

        return count;
    }
};
```
### Another Approach
```
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pos;
        for(int i = 0 ; i < n ; ++i){
            if(nums[i]%k==0) pos.push_back(i);
        }

        int count = 0;
        for(auto& idx : pos){
            int res = nums[idx];
            for(int i = idx ; i < n ; ++i){
                if(nums[i]%k != 0) break;
                res = __gcd(res, nums[i]);
                if(res == k) count++;
            }
        }

        return count;
    }
};
```