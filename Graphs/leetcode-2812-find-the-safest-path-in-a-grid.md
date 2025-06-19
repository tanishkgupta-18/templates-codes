**Problem Link**: [Find the Safest Path in a Grid](https://leetcode.com/problems/find-the-safest-path-in-a-grid/)
---

## Approach
#### step1: We first precompute the safeness factor for each cell using multi source bfs where source is thief.

#### step2: Apply binary search to find minSafe value such that there exists a path for which every cell value satisfies >= minSafe. 

---

```
class Solution {
public:
    void preSafeness(int n, vector<vector<int>>& safeFactor, vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1){
                    safeFactor[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty()){
            auto p = q.front(); q.pop();

            int x = p.first;
            int y = p.second;

            for(int i = 0 ; i < 4 ; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n && safeFactor[nx][ny] == -1){
                    safeFactor[nx][ny] = safeFactor[x][y] + 1;
                    q.push({nx, ny}); 
                }
            }
        }
    }

    bool isValid(int n, vector<vector<int>>& grid, vector<vector<int>>& safeFactor, int& minSafe){
        if(safeFactor[0][0] < minSafe) return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()){
            auto p = q.front(); q.pop();

            int x = p.first;
            int y = p.second;
            if(x == n-1 && y == n-1) return true;
            for(int i = 0 ; i < 4 ; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n && safeFactor[nx][ny] >= minSafe && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({nx, ny}); 
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safeFactor(n, vector<int>(n, -1));
        preSafeness(n, safeFactor, grid);
        int left = 0, right = 2*n, ans = -1;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(isValid(n, grid, safeFactor, mid)){
                ans = mid;
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }

        return ans;
    }
};
```