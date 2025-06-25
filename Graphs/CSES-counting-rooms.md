**Problem Link** [https://cses.fi/problemset/task/1192](https://cses.fi/problemset/task/1192)
```
#include <bits/stdc++.h>
using namespace std;

int n, m;

void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
	if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] == '#') return;

	visited[i][j] = true;

	dfs(i + 1, j, grid, visited);
	dfs(i, j + 1, grid, visited);
	dfs(i, j - 1, grid, visited);
	dfs(i - 1, j, grid, visited);
}

int main() {
	int T = 1;

	while (T--) {
		cin >> n >> m;

		vector<vector<char>> grid(n, vector<char>(m, '#'));

		for (int i = 0 ; i < n ; ++i) {
			for (int j = 0 ; j < m ; ++j) {
				cin >> grid[i][j];
			}
		}

		vector<vector<bool>> visited(n, vector<bool>(m, false));
		int count = 0;
		for (int i = 0 ; i < n ; ++i) {
			for (int j = 0 ; j < m ; ++j) {
				if (grid[i][j] == '.' && !visited[i][j]) {
					count++;
					dfs(i, j, grid, visited);
				}
			}
		}


		cout << count << '\n';
	}

	return 0;
}
```