**Problem Link**: [advantage-shuffle](https://leetcode.com/problems/advantage-shuffle)

## Approach 1
```
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> ms(nums1.begin(), nums1.end());
        int n = nums1.size();
        vector<int> res(n, -1);

        for (int i = 0; i < n; ++i) {
            int num = nums2[i];
            auto it = ms.upper_bound(num); 

            if (it != ms.end()) {
                res[i] = *it;
                ms.erase(it);
            }
        }

        // Fill in remaining -1s with smallest elements (sacrifices)
        for (int i = 0; i < n; ++i) {
            if (res[i] == -1) {
                res[i] = *ms.begin();
                ms.erase(ms.begin());
            }
        }

        return res;
    }
};
```