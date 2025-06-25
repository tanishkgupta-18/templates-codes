**Problem Link** : [sum-of-mutated-array-closest-to-target](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/)

## Approach 1

```
class Solution {
public:
    int calculateSum(vector<int>& arr, int value) {
        int total = 0;
        for (int a : arr) total += min(a, value);
        return total;
    }

    int findBestValue(vector<int>& arr, int target) {
        int low = 0, high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = calculateSum(arr, mid);

            if (sum <= target) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Check between `ans` and `ans+1` which one gives better result
        int sum1 = calculateSum(arr, ans);
        int sum2 = calculateSum(arr, ans + 1);

        if (abs(sum1 - target) <= abs(sum2 - target)) return ans;
        else return ans + 1;
    }
};
```

## Approach 2 (More optimal)
```
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<int> prefix(n + 1, 0);  // prefix sum
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + arr[i];

        int left = 0, right = arr[n - 1], ans = -1;
        int closest = INT_MAX;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Find first index where arr[i] > mid
            auto it = lower_bound(arr.begin(), arr.end(), mid);
            int idx = it - arr.begin();

            // Compute sum: sum of smaller + capped rest
            int currSum = prefix[idx] + (n - idx) * mid;

            int diff = abs(currSum - target);
            // new diff is less than closest or you get same as closest take the min
            if (diff < closest || (diff == closest && mid < ans)) {
                closest = diff;
                ans = mid;
            }

            if (currSum < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return ans;
    }
};

```