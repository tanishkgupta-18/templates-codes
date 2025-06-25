## Sweep Line Algorithm
The sweep line algorithm is a general technique used to solve problems involving intervals on a number line — like time intervals, positions, or ranges.

**It is commonly used to:**

- Count overlaps

- Track changes over time

- Simulate activity along a timeline or 1D/2D space

---

### Problem: Counting the maximum number of people present at the same time over a timeline.

```
#include <bits/stdc++.h>
using namespace std;

int main() {

	int T = 1;

	while (T--) {
		int n;
		cin >> n;

		vector<pair<int, int>> events;
		for (int i = 0 ; i < n ; ++i) {
			int a, b;
			cin >> a >> b;

			events.emplace_back(a, +1);
			events.emplace_back(b, -1);
		}

		sort(events.begin(), events.end());
		int count = 0, maxCount = 0;
		for (auto& event : events) {
			int time = event.first;
			int delta = event.second;

			count += delta;
			maxCount = max(maxCount, count);
		}

		cout << maxCount << '\n';
	}

	return 0;
}
```