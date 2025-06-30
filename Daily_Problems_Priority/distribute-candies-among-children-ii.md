**Problem Link**: [https://leetcode.com/problems/distribute-candies-among-children-ii](https://leetcode.com/problems/distribute-candies-among-children-ii)
```
class Solution {
public:
    const int MOD = 1e9 + 7;

    long long nCk(int n, int k) {
        if (k < 0 || k > n) return 0;
        long long res = 1;
        for (int i = 1; i <= k; ++i) {
            res = res * (n - i + 1) / i;
        }
        return res;
    }

    long long countWays(int n, int limit) {
        // Total ways without upper bounds
        long long total = nCk(n + 2, 2);

        // Subtract cases where one variable exceeds limit
        for (int i = 0; i < 3; ++i) {
            if (n - (limit + 1) >= 0)
                total -= nCk(n - (limit + 1) + 2, 2);
        }

        // Add back cases where two variables exceed limit
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                if (n - 2 * (limit + 1) >= 0)
                    total += nCk(n - 2 * (limit + 1) + 2, 2);
            }
        }

        // Subtract case where all three variables exceed limit
        if (n - 3 * (limit + 1) >= 0)
            total -= nCk(n - 3 * (limit + 1) + 2, 2);

        return total;
    }

    long long distributeCandies(int n, int limit) {
        /*
            x + y + z = n with x, y, z <= limit
            C(n+k−1,k−1)
        */

        return countWays(n, limit);
    }
};
```

This can be solved by many other ways but most optimal solution given above.