**Problem Link** [distant-barcodes](https://leetcode.com/problems/distant-barcodes)

We always place the most frequent barcodes first, and delay placing the same barcode again until another barcode is placed in between.
```
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> freq;
        for (int b : barcodes) freq[b]++;

        // Max heap by frequency
        priority_queue<pair<int, int>> pq;
        for (auto& [num, f] : freq) {
            pq.push({f, num});
        }

        vector<int> res;
        
        while (pq.size() > 1) {
            auto [f1, x] = pq.top(); pq.pop();
            auto [f2, y] = pq.top(); pq.pop();

            res.push_back(x);
            res.push_back(y);

            if (--f1 > 0) pq.push({f1, x});
            if (--f2 > 0) pq.push({f2, y});
        }

        // If one element left
        if (!pq.empty()) {
            res.push_back(pq.top().second);
        }

        return res;
    }
};
```