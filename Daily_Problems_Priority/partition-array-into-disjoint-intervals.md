**Problem Link** [partition-array-into-disjoint-intervals](https://leetcode.com/problems/partition-array-into-disjoint-intervals)

## Approach 1

```
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();

        int j = n-1;
        for(int i = 0 ; i+1 < n ; ++i){
            mx = max(mx, nums[i]);
            mn = min(mn, nums[n-i-1]);
            if(mx <= mn){
                len++;
                return len;
            }

            len++;
        }

        return 0;
    }
};
```

## Approach 2
```
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();

        int currMax = nums[0];
        int leftMax = nums[0];
        int partitionIdx = 0;

        for(int i = 1 ; i < n ; ++i){
            currMax = max(currMax, nums[i]);
            
            /* it means nums[i] < leftMax not a 
            member of right as right_members >= left_members.*/

            if(nums[i] < leftMax){ 
                partitionIdx = i;
                leftMax = currMax;
            }
        }

        return partitionIdx + 1;
    }
};
```