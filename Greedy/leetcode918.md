**Problem Link**: [maximum-sum-circular-subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/)
---

```
int maxSubarraySumCircular(vector<int>& a) {
    int total = 0, n = a.size();

    // Step 1: Kadane's algorithm to find max subarray sum
    int maxSum = a[0], curMax = 0;
    for (int i = 0; i < n; ++i) {
        curMax += a[i];
        maxSum = max(maxSum, curMax);
        curMax = max(curMax, 0);

        total += a[i]; // simultaneously calculate total sum
    }

    // Step 2: Kadane's for min subarray sum (excluding first and last case)
    int minSum = a[0], curMin = 0;
    for (int i = 0; i < n; ++i) {
        curMin += a[i];
        minSum = min(minSum, curMin);
        curMin = min(curMin, 0);
    }

    // Step 3: Final answer
    // If all numbers are negative, maxSum is the correct result
    if (maxSum < 0) return maxSum;

    return max(maxSum, total - minSum);
}
```


## Follow through also find the boundaries of subarray L and R.

```
pair<int, pair<int, int>> kadaneWithBoundaries(const vector<int>& a) {
    int maxSum = a[0], curSum = 0;
    int start = 0, finalL = 0, finalR = 0;

    for (int i = 0; i < a.size(); ++i) {
        if (curSum <= 0) {
            curSum = a[i];
            start = i;
        } else {
            curSum += a[i];
        }

        if (curSum > maxSum) {
            maxSum = curSum;
            finalL = start;
            finalR = i;
        }
    }

    return {maxSum, {finalL, finalR}};
}

tuple<int, int, int> maxSubarraySumCircularWithBoundaries(vector<int>& a) {
    int total = accumulate(a.begin(), a.end(), 0);

    // 1. Normal Kadane
    auto [maxNormal, boundsNormal] = kadaneWithBoundaries(a);
    int l1 = boundsNormal.first, r1 = boundsNormal.second;

    // 2. Find min subarray
    int minSum = a[0], curSum = 0;
    int start = 0, minL = 0, minR = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (curSum >= 0) {
            curSum = a[i];
            start = i;
        } else {
            curSum += a[i];
        }

        if (curSum < minSum) {
            minSum = curSum;
            minL = start;
            minR = i;
        }
    }

    // 3. Check for all-negative
    if (maxNormal < 0)
        return {maxNormal, l1, r1};

    // 4. Circular case: total - minSum
    int maxCircular = total - minSum;
    int l2 = (minR + 1) % a.size();
    int r2 = (minL - 1 + a.size()) % a.size();

    if (maxNormal >= maxCircular)
        return {maxNormal, l1, r1};
    else
        return {maxCircular, l2, r2}; // wrap-around subarray
}
```
