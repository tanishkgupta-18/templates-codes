**Problem Link**: [Apartments](https://cses.fi/problemset/task/1084/)

```
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int T = 1;
 
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;
 
		vector<int> a(n);
		for (auto& x : a) cin >> x;
 
		vector<int> b(m);
		for (auto& x : b) cin >> x;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
 
		int i = 0, j = 0, count = 0;
		while (i < n && j < m) {
			if (abs(a[i] - b[j]) <= k) {
				count++;
				j++;
				i++;
			} else if (b[j] < a[i] - k) {
				j++;
			} else {
				i++;
			}
		}
 
		cout << count << '\n';
	}
 
	return 0;
}
```