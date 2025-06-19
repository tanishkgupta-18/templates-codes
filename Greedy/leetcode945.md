**Problem Link**: [LeetCode 945 - Minimum Increment to Make Array Unique](https://leetcode.com/problems/minimum-increment-to-make-array-unique/)


```
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ops = 0, n = nums.size();
        for(int i = 1 ; i < n ; ++i){
            if(nums[i] <= nums[i-1]){
                int target = nums[i-1]+1;
                ops += (target - nums[i]);
                nums[i] = target;
            }
        }

        return ops;
    }
};
```